#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int d, n;
int a[maxn];

template<typename Cap, typename Cost>
struct mcmf {
    struct edge {
        int v;
        Cap cap, flow;
        Cost cost;
    };
    int n;
    vector<edge> e;
    vector<vector<int>> g;
    vector<Cost> dist, pot;
    vector<Cap> f;
    vector<bool> vis;
    vector<int> par;
    bool n2dijkstra = false;
    mcmf(int n) : n(n), g(n), dist(n), pot(n), f(n), vis(n), par(n) {}
    void add_edge(int u, int v, Cap cap, Cost cost) {
        int k = e.size();
        e.push_back({v, cap, 0, cost});
        e.push_back({u, cap, cap, -cost});
        g[u].push_back(k);
        g[v].push_back(k ^ 1);
    }
    pair<Cap, Cost> solve(int s, int t) {
        Cap flow = 0;
        Cost cost = 0;
        while(true) {
            fill(dist.begin(), dist.end(), numeric_limits<Cost>::max());
            fill(vis.begin(), vis.end(), false);
            dist[s] = 0;
            f[s] = numeric_limits<Cap>::max();
            if(n2dijkstra) {
                while(true) {
                    int x = -1; Cost d = numeric_limits<Cost>::max();
                    for(int i = 0; i < n; i++) {
                        if(!vis[i] && dist[i] < d) {
                            x = i;
                            d = dist[x];
                        }
                    }
                    if(x == -1) break;
                    vis[x] = true;
                    for(int i : g[x]) {
                        Cost d2 = d + e[i].cost + pot[x] - pot[e[i].v];
                        if(!vis[e[i].v] && e[i].flow < e[i].cap && d2 < dist[e[i].v]) {
                            dist[e[i].v] = d2;
                            f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
                            par[e[i].v] = i;
                        }
                    }
                }
            }else {
                priority_queue<pair<Cost, int>, vector<pair<Cost, int>>, greater<pair<Cost, int>>> Q;
                Q.push({0, s});
                while(!Q.empty()) {
                    Cost d; int x;
                    tie(d, x) = Q.top(); Q.pop();
                    if(vis[x]) continue;
                    vis[x] = true;
                    for(int i : g[x]) {
                        Cost d2 = d + e[i].cost + pot[x] - pot[e[i].v];
                        if(!vis[e[i].v] && e[i].flow < e[i].cap && d2 < dist[e[i].v]) {
                            dist[e[i].v] = d2;
                            f[e[i].v] = min(f[x], e[i].cap - e[i].flow);
                            par[e[i].v] = i;
                            Q.push({d2, e[i].v});
                        }
                    }
                }
            }
            if(!vis[t]) break;
            for(int i = 0; i < n; i++) {
                dist[i] += pot[i] - pot[s];
            }
            cost += dist[t] * f[t];
            flow += f[t];
            int x = t;
            while(x != s) {
                e[par[x]].flow += f[t];
                e[par[x] ^ 1].flow -= f[t];
                x = e[par[x] ^ 1].v;
            }
            dist.swap(pot);
        }
        return {flow, cost};
    }

    void out(){
        bool tag = false;
        for(auto id : g[0]){
            if(e[id].flow && e[id].v <= n - 3){
                if(tag) printf("R ");
                tag = true;
                int x = e[id].v - (n - 3) / 2;
                for(int i = 0;i < d;i++) if(a[x] & (1 << i)) printf("%d ", i);
                while(1){
                    int nxt = 0;
                    for(auto i : g[x]){
                        if(e[i].v > (n - 3) / 2 && e[i].v <= n - 3 && e[i].flow){
                            nxt = e[i].v - (n - 3) / 2;
                            break;
                        }
                    }
                    if(!nxt) break;
                    for(int j = 0;j < d;j++) if((a[x] ^ a[nxt]) & (1 << j)) printf("%d ", j);
                    //printf("%d %d--\n", x, nxt);
                    x = nxt;
                }
            }
        }
    }
};

char s[maxn];

int main(){
    scanf("%d%d", &d, &n);
    for(int i = 1;i <= n;i++){
        scanf("%s", s);
        for(int j = d - 1;~j;j--) a[i] = a[i] << 1 | (s[j] - '0');
    }
    mcmf<int, int> Mcmf(n * 2 + 3);
    //0~n,n+1~2n, 2n+1, 2n+2
    for(int i = 0;i <= n;i++){
        for(int j = 1;j <= n;j++) if(i != j && (a[i] & a[j]) == a[i]){
                Mcmf.add_edge(i, j + n, 1, __builtin_popcount(a[i] ^ a[j]) + (i == 0));
                //printf("%d %d %d--\n", i, j + n, __builtin_popcount(a[i] ^ a[j]) + (i == 0));
            }
    }
    for(int i = 0;i <= n;i++) Mcmf.add_edge(n * 2 + 1, i, i == 0 ? 1024 : 1, 0);
    for(int i = 1;i <= n;i++) Mcmf.add_edge(i + n, n * 2 + 2, 1, 0);
    pair<int, int> p = Mcmf.solve(n * 2 + 1, n * 2 + 2);
    printf("%d\n", p.second - 1);
    Mcmf.out();
}