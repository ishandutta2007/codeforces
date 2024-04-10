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
#define vec vector

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
    int n; cin >> n;
    vvi g(n);
    rep(_, n - 1) {
        int u, v; cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi ord;

    function<void(int, int)> dfs = [&] (int v, int p) {
        ord.push_back(v);
        each(u, g[v]) {
            if (u == p) continue;
            dfs(u, v);
            ord.push_back(v);
        }
    };
    dfs(0, -1);
    auto ask = [&] (int l, int r) {
        vi vv;
        for(int i = l; i <= r; ++i) {
            vv.pb(ord[i]);
        }
        sort(all(vv));
        vv.resize(unique(all(vv)) - vv.begin());
        cout << "? " << vv.size() << " ";
        each(v, vv) cout << v + 1 << ' ';
        cout << endl;
        int res; cin >> res;
        return res;
    };
    int l = 0, r = (int)ord.size() - 1;
    int answ = ask(0, r);
    while(r - l > 1) {
        int mid = (r + l) / 2;
        if (ask(mid, r) == answ) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << "! " << ord[l] + 1 << ' ' << ord[r] + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout << setprecision(20-7) << fixed;
    int t = 1;
//     cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}