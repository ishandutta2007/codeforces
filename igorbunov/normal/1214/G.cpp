#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <bitset>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
//#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 
 
//#define int long long
#define endl "\n"

const int MAXN = 2003;

bitset<MAXN> a[MAXN];

set<pair<pair<int, int>, pair<int, int>>> ans;

void modify1(int x1, int x2) {
    bitset<MAXN> a1 = a[x1];
    bitset<MAXN> a2 = a[x2];

    if (((a1 & a2) == a1) || ((a1 & a2) == a2)) {
        return;
    }

    int y1 = (a1 & (~a2))._Find_first();
    int y2 = ((~a1) & a2)._Find_first();
    int x11 = x1;
    int x22 = x2;

    if (y1 > y2) {
        swap(y1, y2);
    }

    if (y1 == y2) {
        cout << "TUDAIN";
    }

    if (x11 > x22) {
        swap(x11, x22);
    }

    ans.insert(make_pair(make_pair(x11, y1), make_pair(x22, y2)));
}

void modify0(int x1, int x2) {
    bitset<MAXN> a1 = a[x1];
    bitset<MAXN> a2 = a[x2];

    if (((a1 & a2) == a1) || ((a1 & a2) == a2)) {
        return;
    }

    int y1 = (a1 & (~a2))._Find_first();
    int y2 = ((~a1) & a2)._Find_first();
    int x11 = x1;
    int x22 = x2;

    if (y1 > y2) {
        swap(y1, y2);
    }

    if (y1 == y2) {
        cout << "TUDAIN";
    }

    if (x11 > x22) {
        swap(x11, x22);
    }

    ans.erase(make_pair(make_pair(x11, y1), make_pair(x22, y2)));
}

signed main() {
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    set<pair<int, int>> s;
    for (int i = 0; i < n; i++) {
        s.insert(make_pair(0, i));
    }

    for (int i = 0; i < q; i++) {
        int a1, l, r;
        cin >> a1 >> l >> r;
        a1--;
        l--;
        r--;

        auto it = s.find({a[a1].count(), a1});
        if (it != s.begin()) {
            modify0(it->second, prev(it)->second);
        }
        if (next(it) != s.end()) {
            modify0(it->second, next(it)->second);
        }
        if (it != s.begin() && next(it) != s.end()) {
            modify1(prev(it)->second, next(it)->second);
        }

        s.erase({a[a1].count(), a1});
        a[a1] ^= (((~bitset<MAXN>() >> l) << l) << (MAXN - r - 1)) >> (MAXN - r - 1);
        s.insert({a[a1].count(), a1});

        it = s.find({a[a1].count(), a1});
        if (it != s.begin()) {
            modify1(it->second, prev(it)->second);
        }
        if (next(it) != s.end()) {
            modify1(it->second, next(it)->second);
        }
        if (it != s.begin() && next(it) != s.end()) {
            modify0(prev(it)->second, next(it)->second);
        }

        if (ans.size() == 0) {
            cout << -1;
            cout << endl;
        } else {
            auto ans1 = *(ans.begin());
            cout << ans1.first.first + 1 << " " << ans1.first.second + 1 << " " << ans1.second.first + 1 << " " << ans1.second.second + 1 << endl;
        }
    }
}