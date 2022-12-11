#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

vector<int> parent;
vector<int> s;

struct datum {
    ll t;
    int u, v;
    bool operator<(const datum& other) const {
        return t < other.t;
    }
};

int cc;

const int mod = 1e9 + 7;

void add(int& a, int b) {
    a += b;
    if (a >= mod) {
        a -= mod;
    }
}

int get(int v) {
    if (parent[v] == v) {
        return v;
    }
    return parent[v] = get(parent[v]);
}

void unite(int a, int b) {
    if (s[a] < s[b]) {
        swap(a, b);
    }
    s[a] += s[b];
    parent[b] = a;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> deg(n + 1);
    deg[0] = 1;
    for (int i = 1; i <= n; ++i) {
        deg[i] = deg[i - 1];
        add(deg[i], deg[i - 1]);
    }

    vector<ll> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<datum> vct(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        vct[i] = {c[u] ^ c[v], u, v};
    }
    sort(all(vct));

    parent.resize(n);
    s.assign(n, 1);
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    cc = n;
    int occ = 0;
    int ans = 0;
    vector<int> active;

    for (int i = 0; i <= m; ++i) {
        if (i == m || (i && vct[i].t != vct[i - 1].t)) {
            add(ans, deg[cc]);
            for (int v : active) {
                parent[v] = v;
                s[v] = 1;
            }
            cc = n;
            active.clear();
            ++occ;
        }
        if (i == m) {
            break;
        }
        int u = get(vct[i].u), v = get(vct[i].v);
        if (u != v) {
            unite(u, v);
            --cc;
            active.pb(u);
            active.pb(v);
        }
    }

    ll z = (1LL << k) - occ;
    z %= mod;
    z *= deg[n];
    z %= mod;
    add(ans, z);
    cout << ans << "\n";

}