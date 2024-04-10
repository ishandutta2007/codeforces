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
const int N = 4e5 + 12;
const ld PI = 3.141592653589793238;

int b[N], h[N];
bool local = 0;
set <pair<int, pair<int, int> > > s;
set <pair<int, int> > ps;
int dp[N];
void solve() {
    int n, k;
    cin >> n;
    h[0] = 1e9;
    b[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
        int x = dp[i - 1];
        while (s.size() > 0 && abs(s.begin()->fi) > h[i]) {
            auto pp = *s.begin();
            ps.erase({-pp.se.se - b[pp.se.fi], h[pp.se.fi]});
            x = max(x, pp.se.se);
            s.erase(s.begin());
        }
        s.insert({-h[i], {i, x}});
        ps.insert({-(b[i] + x), h[i]});
        dp[i] = -ps.begin()->fi;
    }
    cout << dp[n] << "\n";
}


signed main() {
    if (local) {
        freopen("input.txt", "r", stdin);
    }
    ios_base::sync_with_stdio(false); cin.tie(0);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
}