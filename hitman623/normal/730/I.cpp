#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define INF 		INT_MAX
#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

struct graph {
    typedef int flow_type;
    typedef int cost_type;
    struct edge {
        int src, dst;
        flow_type capacity, flow;
        cost_type cost;
        size_t rev;
    };
    void add_edge(int src, int dst, flow_type cap, cost_type cost) {
        adj[src].push_back({src, dst, cap, 0, cost, adj[dst].size()});
        adj[dst].push_back({dst, src, 0, 0, -cost, adj[src].size()-1});
    }
    int n;
    vector<vector<edge>> adj;
    graph(int n) : n(n), adj(n) { }
    pair<flow_type, cost_type> min_cost_max_flow(int s, int t) {
        flow_type flow = 0;
        cost_type cost = 0;
        for (int u = 0; u < n; ++u)for (auto &e: adj[u]) e.flow = 0;
        vector<cost_type> p(n, 0);
        auto rcost = [&](edge e) { return e.cost + p[e.src] - p[e.dst]; };
        for (int iter = 0; ; ++iter) {
            vector<int> prev(n, -1); prev[s] = 0;
            vector<cost_type> dist(n, INF); dist[s] = 0;
            if (iter == 0) {
                vector<int> count(n); count[s] = 1;
                queue<int> que; 
                for (que.push(s); !que.empty(); ) {
                    int u = que.front(); que.pop();
                    count[u] = -count[u];
                    for (auto &e: adj[u]) {
                        if (e.capacity > e.flow && dist[e.dst] > dist[e.src] + rcost(e)) {
                            dist[e.dst] = dist[e.src] + rcost(e);
                            prev[e.dst] = e.rev;
                            if (count[e.dst] <= 0) {
                                count[e.dst] = -count[e.dst] + 1;
                                que.push(e.dst);
                            }
                        }
                    }
                }
            }
            else {
                typedef pair<cost_type, int> node;
                priority_queue<node, vector<node>, greater<node>> que;
                que.push({0, s});
                while (!que.empty()) {
                    node a = que.top(); que.pop();
                    if (a.S == t) break;
                    if (dist[a.S] > a.F) continue;
                    for (auto e: adj[a.S]) {
                        if (e.capacity > e.flow && dist[e.dst] > a.F + rcost(e)) {
                            dist[e.dst] = dist[e.src] + rcost(e);
                            prev[e.dst] = e.rev;
                            que.push({dist[e.dst], e.dst});
                        }
                    }
                }
            }
            if (prev[t] == -1) break;
            for (int u = 0; u < n; ++u) 
                if (dist[u] < dist[t]) p[u] += dist[u] - dist[t];
            function<flow_type(int,flow_type)> augment = [&](int u, flow_type cur) {
                if (u == s) return cur;
                edge &r = adj[u][prev[u]], &e = adj[r.dst][r.rev];
                flow_type f = augment(e.src, min(e.capacity - e.flow, cur));
                e.flow += f; r.flow -= f;
                return f;
            };
            flow_type f = augment(t, INF);
            flow += f;
            cost += f * (p[t] - p[s]);
        }
        return {flow, cost};
    }
};


void solve(){
	int n,p,s;
	cin>>n>>p>>s;
	vi a(n+1),b(n+1);
	int ans=0;
	rep(i,1,n+1)cin>>a[i],ans+=a[i];
	rep(i,1,n+1)cin>>b[i],ans+=b[i];
	graph g(n+5);
	rep(i,1,n+1){
		g.add_edge(0,i,1,0);
		g.add_edge(i,n+1,1,b[i]);
	}
	rep(i,1,n+1){
		g.add_edge(i,n+2,1,a[i]);
		g.add_edge(i,n+3,1,a[i]+b[i]);
	}
	g.add_edge(n+1,n+4,p,0);
	g.add_edge(n+2,n+4,s,0);
	g.add_edge(n+3,n+4,n-p-s,0);
	cout<<ans-g.min_cost_max_flow(0,n+4).S<<endl;
	vi ps,ss;
	rep(j,1,n+1){
		for(auto i:g.adj[j]){
			if(i.src>0 and i.src<=n and i.dst==n+1 and i.flow>0){
				ps.pb(i.src);
			}
			if(i.src>0 and i.src<=n and i.dst==n+2 and i.flow>0){
				ss.pb(i.src);
			}
		}		
	}
	rep(i,0,sz(ps))cout<<ps[i]<<" ";
	cout<<endl;
	rep(i,0,sz(ss))cout<<ss[i]<<" ";
	cout<<endl;
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}