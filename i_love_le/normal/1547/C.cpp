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
const int md = 998244353;

void solve() {
    int k, n, m; cin >> k >> n >> m;
    vi a(n), b(m);
    each(x, a) cin >> x;
    each(x, b) cin >> x;
    int i = 0;
    vi r;
    each(x, a) {
        while(x > k) {
            if (i == m || b[i] > k) {
                cout << "-1\n";
                return;
            }
            r.push_back(b[i]);
            k += (b[i++] == 0);
        }
        k += (x == 0);
        r.push_back(x);
    }
    while(i < m) {
        if (b[i] > k) {
            cout << "-1\n";
            return;
        }
        r.push_back(b[i]);
        k += (b[i++] == 0);
    }
    each(x, r) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}