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
    ll m;
    vi a(n);
    {
        int x = 0;
        rep(i, n) {
            int y;
            cin >> y;
            a[i] = y - x;
            swap(x, y);
        }
    }
    cin >> m;
    ll S = 0;
    rep(i, n) S += 1ll * a[i] * a[i];
    if (S <= m) {
        cout << "0\n";
        return;
    }
    auto checki = [&](int i, ll k) {
        ll t1 = a[i] / k;
        ll t2 = t1 + 1;
        ll ct2 = a[i] % k;
        ll ct1 = k - ct2;
        ll res = 1ll * t1 * t1 * ct1;
        res += 1ll * t2 * t2 * ct2;
        return res;
    };
    vl res(n);
    auto check = [&](ll val) {
        ll sum = 0;
        rep(i, n) {
            ll L = 0;
            ll R = a[i];
            while (R - L > 1) {
                ll mid = (R + L) / 2;
                if (checki(i, mid) - checki(i, mid + 1) >= val) {
                    L = mid;
                } else {
                    R = mid;
                }
            }
            res[i] = L;
            sum += checki(i, L + 1);
        }
        return sum <= m;
    };
    ll L = 0;
    ll R = INF;
    while (R - L > 1) {
        ll mid = (R + L) / 2;
        if (check(mid)) {
            L = mid;
        } else {
            R = mid;
        }
    }
    check(R);
    ll need = -m;
    vl can;
    ll ans = 0;
    rep(i, n) {
        ll cur = checki(i, res[i] + 1);
        need += cur;
        ans += res[i];
    }
    assert(need > 0 && L > 0);
    cout << (need + L - 1) / L + ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}