#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define L 1
int n, m, c, q;
vi sz;
vi spec;
vi p;
vvi g;
vector<unordered_set<int>> zav;
vector<unordered_set<int>> have;
vector<unordered_map<int, int>> col;

int get_par(int a) {
    if(p[a] == a) return a;
    int par = get_par(p[a]);
    p[a] = par;
    return par;
}

bool eq(int a, int b) {
    return get_par(a) == get_par(b);
}

void join(int a, int b) {
    a = get_par(a);
    b = get_par(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    for(const auto& el : zav[b]) {
        have[el].erase(b);
        have[el].insert(a);
        zav[a].insert(el);
    }
    zav[b].clear();
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
    cin >> n >> m >> c >> q;
    sz.resize(n);
    g.resize(n);
    vector<array<int, 3>> e(m + q);
    for(int i = 0; i < m; i++) {
        cin >> e[i][0] >> e[i][1] >> e[i][2];
        --e[i][0];
        --e[i][1];
        ++sz[e[i][0]];
        ++sz[e[i][1]];
    }
    for(int i = m; i < m + q; i++) {
        char c1;
        cin >> c1;
        if(c1 == '+') {
            cin >> e[i][0] >> e[i][1] >> e[i][2];
            --e[i][0];
            --e[i][1];
            ++sz[e[i][0]];
            ++sz[e[i][1]];
        } else {
            e[i][2] = -1;
            cin >> e[i][0] >> e[i][1];
            --e[i][0];
            --e[i][1];
        }
    }
    spec.assign(n, false);
    for(int i = 0; i < n; i++) {
        if(sz[i] >= L) {
            spec[i] = true;
        }
    }
    p.resize(n);
    sz.assign(n, 1);
    for(int i = 0; i < n; i++) {
        p[i] = i;
    }
    zav.resize(n);
    have.resize(n);
    col.resize(n);
    for(int i = 0; i < m + q; i++) {
        if(e[i][2] == -1) {
            int v = e[i][0];
            int u = e[i][1];
            if(eq(v, u)) {
                cout << "Yes\n";
                continue;
            }
            if(spec[u]) {
                if(have[u].find(get_par(v)) != have[u].end()) {
                    cout << "Yes\n";
                    continue;
                }
            } else {
                bool ok = false;
                for(const auto& el : g[u]) {
                    if(eq(v, el)) {
                        ok = true;
                        break;
                    }
                }
                if(ok) {
                    cout << "Yes\n";
                    continue;
                }
            }
            cout << "No\n";
        } else {
            int v = e[i][0];
            int u = e[i][1];
            int w = e[i][2];
            g[v].push_back(u);
            g[u].push_back(v);
            auto it = col[v].find(w);
            if(it != col[v].end()) {
                join(u, it->second);
            }
            it = col[u].find(w);
            if(it != col[u].end()) {
                join(v, it->second);
            }
            col[v][w] = u;
            col[u][w] = v;
            if(spec[v] && !eq(v, u)) {
                have[v].insert(get_par(u));
                zav[get_par(u)].insert(v);
            }
            if(spec[u] && !eq(v, u)) {
                have[u].insert(get_par(v));
                zav[get_par(v)].insert(u);
            }
        }
    }
}