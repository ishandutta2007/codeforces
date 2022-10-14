#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
struct sat {
    int n;
    vector<vector<int>> g;
    vector<vector<int>> gt;
    vector<int> vis, topo, comp;
    int cur;
    sat(int N) : n(N), g(2*n), gt(2*n), vis(2*n), comp(2*n), cur(1) {}
    void add(int i, int j) {
        //cout << i << " OR " << j << endl;
        g[i^1].push_back(j);
        g[j^1].push_back(i);
        gt[j].push_back(i^1);
        gt[i].push_back(j^1);
    }
    void tsort(int v) {
        vis[v] = 1;
        for(auto i : g[v]) if(!vis[i])
            tsort(i);
        topo.push_back(v);
    }
    void scc(int v) {
        comp[v] = cur;
        for(auto i : gt[v])
            if(!comp[i])
                scc(i);
    }
    vector<int> solve() {
        for(int i = 0; i < 2*n; i++) if(!vis[i]) tsort(i);
        reverse(all(topo));
        //u before v -> there is v<-u path or they are not connected
        for(auto i : topo) if(!comp[i]) {
            scc(i);
            cur++;
        }
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            if(comp[2*i] == comp[2*i+1]) return {};
            a[i] = comp[2*i] > comp[2*i+1];
        }
        return a;
    }
};
int n, m;
vector<array<int, 4>> edges;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;  
    edges.resize(m);
    map<array<int, 2>, int> crap;
    for(auto &[a, b, c, d] : edges) {
        cin >> a >> b >> c >> d, a--, b--;
        if(crap[{a, c}]++>1 || crap[{b, c}]++>1) { 
            cout << "No\n"; exit(0);
        }
    }
    auto check = [&](int z) {
        vector<vector<array<int, 3>>> g(n);
        int id = 0;
        for(auto &[a, b, c, d] : edges) {
            g[a].push_back({c, b, id});
            g[b].push_back({c, a, id++});
        }
        int n1 = id;
        for(int i = 0; i < n; i++) sort(all(g[i])), n1 += g[i].size();
        sat solver(n1);
        for(int i = 0; i < edges.size(); i++) if(edges[i][3] > z)
            solver.add(2*i+1, 2*i+1);
        int ptr = id;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < g[i].size(); j++) {
                for(int z = 3; z-->1;)
                    if(j>=z && g[i][j][0] == g[i][j-z][0]) {
                        solver.add(2*g[i][j][2], 2*g[i][j-z][2]);
                        //if(z>1) {
                        //    cout <<"No";
                        //    exit(0);
                        //}
                    }
            }
            /*for(int j = 0; j < g[i].size(); j++) 
            for(int k = 0; k < j; k++)  if(g[i][j][0]==g[i][k][0])
                solver.add(2*g[i][j][2], 2*g[i][k][2]), solver.add(2*g[i][j][2]+1, 2*g[i][k][2]+1);
            for(int j = 0; j < g[i].size(); j++) 
            for(int k = 0; k < j; k++) 
                solver.add(2*g[i][j][2]+1, 2*g[i][k][2]+1);
            */
            int lst = -1;
            for(int j = 0; j < g[i].size(); j++) {
                //cout << g[i][j][2] << ".\n";
                if(lst != -1) {
                    solver.add(2*g[i][j][2]+1, 2*lst+1);
                    solver.add(2*lst+1, 2*ptr);
                }
                solver.add(2*g[i][j][2]+1, 2*ptr);
                lst = ptr++;
            }
        }
        return solver.solve();
    };
    int ti = -1;
    for(int z = 1<<30; z>>=1;) {
        ti += z;
        auto sol = check(ti);
        if(sol.size()) ti -= z;
    }
    auto ans = check(++ti);
    if(ans.empty()) {
        cout << "No\n";
        exit(0);
    } else cout << "Yes\n";
    //cout << ans.size() << endl;
    //for(auto i : ans) cout << i << " "; cout << endl;
    vector<int> rem;
    for(int i = 0; i < m; i++) if(ans[i]) rem.push_back(i+1);
    cout << ti << " " << rem.size() << '\n';
    for(auto &i : rem) cout << i << " "; cout << '\n';
}