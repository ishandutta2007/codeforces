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
#define f0r(i, a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

const int INFi = 2e9;

int solveL(vi a, int n) {
    int mx = *max_element(all(a));
    int imx = max_element(all(a)) - a.begin();
    vector<pair<int, int>> toL(n, {INFi, INFi});
    vector<pair<int, int>> toR(n, {INFi, INFi});
    {
        pair<int, int> cur = {0, 0};
        rep(i, n) {
            if (a[i] < cur.second) break;
            if (a[i] > cur.first) {
                cur.first = a[i];
            } else {
                assert(a[i] > cur.second);
                cur.second = a[i];
            }
            toL[i] = cur;
        }
    }
    {
        pair<int, int> cur = {0, 0};
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] < cur.second) break;
            if (a[i] > cur.first) {
                cur.first = a[i];
            } else {
                assert(a[i] > cur.second);
                cur.second = a[i];
            }
            toR[i] = cur;
        }
    }
    if (toR[imx].first == INFi) return 0;
    int y = toR[imx].first;
    int x = toR[imx].second;
    int nd = -1;
    assert(y == mx);
    int res = 0;
    for (int i = imx - 1; i >= 0; --i) {
        if (nd != -1) {
            assert(x < nd && nd < y);
        }
        if (toL[i].first != INFi && a[i] > x) {
            int val2 = toL[i].first ^a[i] ^toL[i].second;
            if (nd == -1) {
                if (val2 < y) {
                    res++;
                }
            } else {
                if (a[i] > nd && val2 < y) {
                    res++;
                } else if (val2 < nd) {
                    res++;
                }
            }
        }
        if (a[i] < x) {
            nd = -1;
            if (y < a[i]) break;
            y = a[i];
            continue;
        }
        if (a[i] > y) {
            nd = -1;
            if (x > a[i]) break;
            x = a[i];
            continue;
        }
        if (nd == -1) {
            nd = a[i];
            continue;
        }
        if (nd > a[i]) {
            y = nd;
            nd = a[i];
        } else {
            x = nd;
            nd = a[i];
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = solveL(a, n);
    reverse(all(a));
    ans += solveL(a, n);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}