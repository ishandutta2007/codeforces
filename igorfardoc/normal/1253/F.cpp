#include<bits/stdc++.h>
#define inf 1000000000000000000ll
#define log 17
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<pair<int, int>>> g;
vector<vector<pair<int, ll>>> g1;
vvi table1;
vector<vector<ll>> table2;
vi tin, tout;
int timer = 0;
vi p;

int get_par(int a) {
    if(p[a] == a) {
        return a;
    }
    int par = get_par(p[a]);
    p[a] = par;
    return par;
}

bool eq(int a, int b) {
    return get_par(a) == get_par(b);
}

void join(int a, int b) {
    if(eq(a, b)) return;
    a = get_par(a);
    b = get_par(b);
    p[a] = b;
}

void dfs1(int v, int p, ll w) {
    //cout << v << endl;
    table1[v][0] = p;
    table2[v][0] = w;
    for(int i = 1; i <= log; i++) {
        table1[v][i] = table1[table1[v][i - 1]][i - 1];
        table2[v][i] = max(table2[v][i - 1], table2[table1[v][i - 1]][i - 1]);
    }
    tin[v] = timer++;
    for(auto& u1 : g1[v]) {
        int u = u1.first;
        ll w = u1.second;
        if(u == p) continue;
        dfs1(u, v, w);
    }
    tout[v] = timer++;
}

bool upper(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

ll get_max(int a, int b) {
    ll ans = 0;
    for(int i = log; i >= 0; i--) {
        int a1 = table1[a][i];
        if(!upper(a1, b)) {
            ans = max(ans, table2[a][i]);
            a = a1;
        }
    }
    for(int i = log; i >= 0; i--) {
        int b1 = table1[b][i];
        if(!upper(b1, a)) {
            ans = max(ans, table2[b][i]);
            b = b1;
        }
    }
    if(table1[a][0] != b) {
        ans = max(ans, table2[b][0]);
    } 
    if(table1[b][0] != a) {
        ans = max(ans, table2[a][0]);
    }
    return ans;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    g.resize(n);
    g1.resize(n);
    for(int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        --v;
        --u;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    set<pair<ll, int>> s;
    vector<ll> d(n, inf);
    for(int i = 0; i < k; i++) {
        d[i] = 0;
        s.insert({0, i});
    }
    while(!s.empty()) {
        auto it = s.begin();
        int v = it->second;
        ll dst = it->first;
        s.erase(it);
        for(auto& u1 : g[v]) {
            int u = u1.first;
            int w = u1.second;
            ll dsthere = w + dst;
            if(dsthere < d[u]) {
                auto it = s.find({d[u], u});
                if(it != s.end()) {
                    s.erase(it);
                }
                d[u] = dsthere;
                s.insert({d[u], u});
            }
        }
    }
    vector<array<ll, 3>> e;
    for(int v = 0; v < n; v++) {
        for(auto& u1 : g[v]) {
            int u = u1.first;
            int w = u1.second;
            e.push_back({d[u] + d[v] + w, v, u});
        }
    }
    sort(e.begin(), e.end());
    p.resize(n);
    for(int i = 0; i < n; i++) {
        p[i] = i;
    }
    for(int i = 0; i < e.size(); i++) {
        int v = e[i][1];
        int u = e[i][2];
        ll w = e[i][0];
        if(!eq(v, u)) {
            join(v, u);
            g1[v].push_back({u, w});
            g1[u].push_back({v, w});
            //cout << v << ' ' << u << ' ' << w << endl;
        }
    }
    tin.resize(n);
    tout.resize(n);
    table1.assign(n, vi(log + 1));
    table2.assign(n, vector<ll>(log + 1));
    //cout << 1234 << endl;
    dfs1(0, 0, 0);
    //cout << 1234 << endl;
    //cout << table2[2][15] << endl;
    for(int i = 0; i < q; i++) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        cout << get_max(v, u) << '\n';
    }
}