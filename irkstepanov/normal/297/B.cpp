#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 bigInt;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, m, k;
    cin >> n >> m >> k;

    multiset<int> a, b;
    while (n--) {
        int x;
        cin >> x;
        a.insert(x);
    }

    while (m--) {
        int x;
        cin >> x;
        if (a.count(x)) {
            auto it = a.lower_bound(x);
            a.erase(it);
            continue;
        }
        b.insert(x);
    }

    while (!a.empty() && !b.empty()) {
        auto x = --a.end();
        auto y = --b.end();
        if (*x > *y) {
            cout << "YES\n";
            return 0;
        }
        a.erase(x);
        b.erase(y);
    }

    if (a.empty()) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

}