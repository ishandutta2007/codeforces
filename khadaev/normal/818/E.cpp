#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define ford(i, a, n) for (int i = (int)(n - 1); i >= (int)(a); --i)
#define fore(i, a, n) for (int i = (int)(a); i <= (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
    for (auto i : a) cerr << i << ' ';\
    cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

vector<pair<int, int>> factor(int k) {
    vector<pair<int, int>> ans;
    for (int i = 2; i * i <= k; ++i) {
        if (k % i == 0) {
            ans.eb(i, 0);
            while (k % i == 0) {
                k /= i;
                ++ans.back().sn;
            }
        }
    }
    if (k > 1) {
        ans.eb(k, 1);
    }
    return ans;
}

vector<int> solve(vector<int> vals, int k) {
    int n = vals.size();
    vector<int> ans(n);
    int x = 0, y = 0, sum = 0;
    while (x < n) {
        while (y < n && sum < k) {
            sum += vals[y];
            ++y;
        }
        if (sum >= k) ans[x] = y;
        else ans[x] = INF;
        sum -= vals[x];
        ++x;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    vector<pair<int, int>> pr = factor(k);
    vector<int> mn(n);
    forn(i, 0, n) mn[i] = i + 1;
    for (auto p : pr) {
        vector<int> pws(n);
        forn(i, 0, n) {
            int x = a[i];
            while (x % p.fs == 0) {
                x /= p.fs;
                ++pws[i];
            }
        }
        vector<int> _mn = solve(pws, p.sn);
        forn(i, 0, n) mn[i] = max(mn[i], _mn[i]);
    }
    //forn(i, 0, n) cout << mn[i] << ' ';
    ll ans = 0;
    forn(i, 0, n) {
        if (mn[i] == INF) continue;
        ans += n + 1 - mn[i];
    }
    cout << ans << '\n';
}