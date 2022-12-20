#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <tgmath.h>
#define fi first
#define se second
#define ll long long
#define ld long double
#define int long long
using namespace std;
const int N = 2e5 + 12;
const ld PI = 3.141592653589793238;

bool local = 0;
int gcd(int a, int b) {
    if (a < b)
        swap(a, b);
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

bool use[N];
int nxt[N];

int get_next(int x) {
    if (use[nxt[x]])
        return nxt[x];
    else
        return nxt[x] = get_next(nxt[x]);

}

set<pair<int, int> > events;
int m[N];

void check(int i) {
    int a = m[i];
    int b = m[get_next(i)];
    if (gcd(a, b) == 1)
        events.insert({i, get_next(i)});
}

void solve() {
    int n, k;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> m[i];
        use[i] = 1;
        nxt[i] = (i + 1) % n;
    }
    for (int i = 0;  i< n; ++i)
        check(i);
    vector<int> ans;
    int now = 0;
    while (events.size() > 0 && ans.size() != n) {
        auto it = events.lower_bound({now, 0});
        if (it == events.end()) {
            now = 0;
            continue;
        }
        auto a = (*it).fi;
        auto b = (*it).se;
        events.erase(it);
        if (!use[a] || !use[b]) {
            continue;
        }
        now = b;
        use[b] = 0;
        ans.push_back(b);
        if (a != b)
            check(a);
    }
    events.clear();
    cout << ans.size() << ' ';
    for (auto x : ans)
        cout << x + 1 << ' ';
    cout << "\n";
}


signed main() {
    if (local) {
        freopen("input.txt", "r", stdin);
    }
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
}