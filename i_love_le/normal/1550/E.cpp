#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
#define rep1n(i, n) for(int i = 1; i <= (n); ++i)
#define repr(i, n) for(int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for(auto &x : a)
#define ar array

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

template<class T> bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T> bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int mxN = 2e5;
const ll INF = 1e18;
const int md = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    str s; cin >> s;
    int l = 0, r = n + 1;
    auto chck = [&] (int x) {
        vector<vi> nxt(k, vi(n, n + 1));
        rep(c, k) {
            int lst = n + 1;
            int cur = 0;
            repr(i, n) {
                if (s[i] == char('a' + c) || s[i] == '?') {
                    cur++;
                } else {
                    cur = 0;
                }
                if (cur >= x) {
                    nxt[c][i] = i + x;
                } else {
                    nxt[c][i] = lst;
                }
                lst = nxt[c][i];
            }
        }
        vi dp(1 << k, n + 1);
        dp[0] = 0;
        rep(mask, 1 << k) {
            if (dp[mask] >= n) continue;
            rep(i, k) {
                if (Bit(mask, i)) continue;
                ckmin(dp[mask|(1<<i)], nxt[i][dp[mask]]);
            }
        }
        return dp[(1<<k)-1] <= n;
    };
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if (chck(mid)) l = mid;
        else r = mid;
    }
    cout << l << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}