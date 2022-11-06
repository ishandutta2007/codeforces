#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
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

vector<ll> pref(vector<int> &a) {
    int sum = 0;
    for (int x : a) sum += x;
    int sz = 2 * sum + 1;
    vector<ll> ans(sz), cnt1(sz), cnt2(sz);
    cnt1[sum] = 1;
    for (int x : a) {
        fore(i, x, sz - x - 1) {
            cnt2[i - x] += cnt1[i];
            cnt2[i + x] = cnt1[i];
            if (cnt2[i - x] >= MOD) cnt2[i - x] -= MOD;
        }
        forn(i, 0, sz) {
            ans[i] += cnt2[i];
            if (ans[i] >= MOD) ans[i] -= MOD;
        }
        fill(all(cnt1), 0);
        cnt1.swap(cnt2);
    }
    return ans;
}

ll solve(vector<int> &a) {
    int n = a.size();
    if (n == 1) return 0;
    vector<int> b(n / 2), c(n - n / 2);
    forn(i, 0, n / 2) b[n / 2 - 1 - i] = a[i];
    forn(i, n / 2, n) c[i - n / 2] = a[i];
    ll ans = solve(b) + solve(c);
    vector<ll> pb = pref(b), pc = pref(c);
    int sb = pb.size() / 2, sc = pc.size() / 2;
    int sum = min(sb, sc);
    fore(i, -sum, sum) {
        ans += pb[sb + i] * pc[sc - i];
        ans %= MOD;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i, 0, n) cin >> a[i];
    cout << solve(a) << '\n';
}