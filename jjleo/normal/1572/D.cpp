#include <bits/stdc++.h>
#define maxn 1100086

using namespace std;

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
    mcmf(int n) : n(n), g(n), dist(n), pot(n), f(n), vis(n), par(n) {}
    void add_edge(int u, int v, Cap cap, Cost cost) {
        int k = e.size();
        e.push_back({v, cap, 0, cost});
        e.push_back({u, cap, cap, -cost});
        g[u].push_back(k);
        g[v].push_back(k ^ 1);
    }
    
    void pre(int s, int t){
    	fill(pot.begin(), pot.end(), numeric_limits<Cost>::max());
    	queue<int> q;
    	pot[s] = 0, q.push(s), vis[s] = true;
    	while(!q.empty()){
    		int x = q.front();q.pop(), vis[x] = false;
    		for(int i : g[x]){
    			if(e[i].cap == e[i].flow) continue;
    			int to = e[i].v;
    			if(pot[x] + e[i].cost < pot[to]){
    				pot[to] = pot[x] + e[i].cost;
    				if(!vis[to]) q.push(to), vis[to] = true;
				}
			}
		}
	}
    
    pair<Cap, Cost> solve(int s, int t) {
    	pre(s, t);
        Cap flow = 0;
        Cost cost = 0;
        while(true) {
            fill(dist.begin(), dist.end(), numeric_limits<Cost>::max());
            fill(vis.begin(), vis.end(), false);
            dist[s] = 0;
            f[s] = numeric_limits<Cap>::max();
            
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
};

int n, k, m;
int a[maxn];
tuple<int, int, int> e[maxn * 10];
int id[maxn], Id[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0;i < (1 << n);i++) scanf("%d", &a[i]);
	for(int i = 0;i < (1 << n);i++) if(__builtin_popcount(i) & 1){
		for(int j = 0;j < n;j++) e[++m] = make_tuple(a[i] + a[i ^ (1 << j)], i, i ^ (1 << j));
	}
	int cnt = min((n * 2 - 1) * (k - 1) + 1, m);
	nth_element(e + 1, e + cnt, e + 1 + m, greater<tuple<int, int, int> >());
	int tot = 0;
	for(int i = 1;i <= m;i++) if(get<0>(e[i]) > get<0>(e[cnt])) e[++tot] = e[i];
	for(int i = 1;i <= m && tot < cnt;i++) if(get<0>(e[i]) == get<0>(e[cnt])) e[++tot] = e[i];
	tot = 0;
	for(int i = 1;i <= cnt;i++){
		if(!id[get<1>(e[i])]) id[get<1>(e[i])] = tot, Id[tot++] = 0;
		if(!id[get<2>(e[i])]) id[get<2>(e[i])] = tot, Id[tot++] = 1;
	}
	tot += 3;
	mcmf<int, int> Mcmf(tot);
	for(int i = 1;i <= cnt;i++) Mcmf.add_edge(id[get<1>(e[i])], id[get<2>(e[i])], 1, -get<0>(e[i]));
	for(int i = 0;i < tot - 3;i++){
		if(!Id[i]) Mcmf.add_edge(tot - 1, i, 1, 0);
		else Mcmf.add_edge(i, tot - 2, 1, 0);
	}
	Mcmf.add_edge(tot - 2, tot - 3, k, 0);
	printf("%d", -Mcmf.solve(tot - 1, tot - 3).second);
}