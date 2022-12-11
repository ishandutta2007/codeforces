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

void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    rep(i, n) rep(j, m) {
            char x;
            cin >> x;
            a[i][j] = x - '0';
        }
    vvi u(n, vi(m));
    rep(i, n) {
        rep(j, m) {
            if (u[i][j]) continue;
            if (a[i][j] == 0) continue;
            if (i - 1 >= 0 && a[i - 1][j]) {
                cout << "NO\n";
                return;
            }
            if (j - 1 >= 0 && a[i][j - 1]) {
                cout << "NO\n";
                return;
            }
            int k = j;
            while (k < m && a[i][k] == 1) {
                if (u[i][k] || (i - 1 >= 0 && a[i - 1][k])) {
                    cout << "NO\n";
                    return;
                }
                k++;
            }
            for (int t = i; t < n; ++t) {
                if (a[t][j] == 0) break;
                for (int d = j; d < k; ++d) {
                    if (a[t][d] == 0) {
                        cout << "NO\n";
                        return;
                    }
                    u[t][d] = 1;
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}