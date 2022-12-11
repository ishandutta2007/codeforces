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

struct dsu {
    vi dsu;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        iota(all(dsu), 0);
    }

    void unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
    }
};

void solve() {
    int n, q, s, d; cin >> n >> q >> s >> d;
    vi a(n);
    each(x, a) cin >> x;
    dsu D;
    map<int, int> mp;
    rep(i, n) mp[a[i]] = i;
    D.build(n);
    vector<ar<int, 3>> edgs;
    while(true) {
        vector<vi> to(n);
        rep(i, n) {
            to[D.get_dsu(i)].push_back(i);
        }
        bool ok = true;
        rep(i, n) ok &= (sz(to[i]) != n);
        if (!ok) break;
        set<int> have;
        each(x, a) have.insert(x);
        vector<ar<int, 3>> newe;
        rep(i, n) {
            if (to[i].empty()) continue;
            each(j, to[i]) have.erase(a[j]);
            vector<ar<int, 3>> vv;
            each(j, to[i]) {
                auto it = have.lower_bound(a[j] + d);
                if (it != have.end()) {
                    vv.pb({(*it) - (a[j] + d), j, (*it)});
                }
                if (it != have.begin()) {
                    it--;
                    vv.pb({-(*it) + (a[j] + d), j, (*it)});
                }
                it = have.lower_bound(a[j] - d);
                if (it != have.end()) {
                    vv.pb({(*it) - (a[j] - d), j, (*it)});
                }
                if (it != have.begin()) {
                    it--;
                    vv.pb({-(*it) + (a[j] - d), j, (*it)});
                }
            }
            sort(all(vv));
            vv[0][2] = mp[vv[0][2]];
            newe.pb(vv[0]);
            each(j, to[i]) have.insert(a[j]);
        }
        for(auto &[ww, i, j] : newe) {
            edgs.pb({ww, i, j});
            D.unio(i, j);
        }
    }
    vector<ar<int, 3>> qq(q);
    rep(i, q) {
        cin >> qq[i][1] >> qq[i][0];
        qq[i][2] = i;
    }
    vi ans(q);
    sort(all(qq));
    sort(all(edgs));
    dsu DD;
    DD.build(n);
    int j = 0;
    s--;
    for(auto &[k, i, qi] : qq) {
        i--;
        while(j < sz(edgs) && edgs[j][0] <= k) {
            DD.unio(edgs[j][1], edgs[j][2]);
            j++;
        }
        if (DD.get_dsu(s) == DD.get_dsu(i)) {
            ans[qi] = 1;
        } else {
            ans[qi] = 0;
        }
    }
    rep(i, q) cout << (ans[i] ? "Yes\n" : "No\n");
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