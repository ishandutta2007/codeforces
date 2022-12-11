#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 4e5 + 10;
const int LG = 100;

void solve() {
    int n;
    cin >> n;
    vi h(n);
    rep(i, n) cin >> h[i];
    ll ans = INF;
    int mx = *max_element(all(h));
    for (auto x : {mx, mx + 1}) {
        ll cnt1 = 0;
        ll cnt2 = 0;
        for (auto &y : h) {
            ll need = x - y;
            if (need % 2) {
                cnt1++;
                need--;
            }
            cnt2 += need / 2;
        }
        // (cnt1 + 2 * k) * 2 - 1 < (cnt2 - (k - 1)) * 2
        // cnt1 * 2 + 4 * k - 1 < cnt2 * 2 - 2 * k + 2
        // 6 * k < cnt2 * 2 - cnt1 * 2 + 3
        if ((cnt1 + 2) * 2 - 1 < cnt2 * 2) {
            ll k = (cnt2 * 2 - cnt1 * 2 + 2) / 6;
            assert(k >= 0);
            cnt1 += 2 * k;
            cnt2 -= k;
        }
        ans = min(ans, max(cnt1 * 2 - 1, cnt2 * 2));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}