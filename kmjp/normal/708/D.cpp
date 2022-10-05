#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to, capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV];
	void add_edge(int x,int y, int cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	pair<int,V> mincost(int from, int to, int flow=1<<30) { // return(flow,cost);
		V res=0; int i,v,tflow=0;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, numeric_limits<V>::max()/2);
			dist[from]=0;
			priority_queue<pair<int,int> > Q;
			Q.push(make_pair(0,from));
			while(Q.size()) {
				int d=-Q.top().first, cur=Q.top().second;
				Q.pop();
				if(dist[cur]!=d) continue;
				if(d==numeric_limits<V>::max()/2) break;
				FOR(i,E[cur].size()) {
					edge &e=E[cur][i];
					if(e.capacity>0 && dist[e.to]>d+e.cost) {
						dist[e.to]=d+e.cost;
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) break;
			int lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			tflow+=lc;
			res += lc*dist[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return {tflow,res};
	}
};

int N,M;
MinCostFlow<300,ll> mcf;
ll out[101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	mcf.add_edge(N-1,0,1<<30,0);
	
	int def=0;
	while(M--) {
		cin>>x>>y>>i>>j;
		x--,y--;
		out[x] += j;
		out[y] -= j;
		if(j<=i) {
			mcf.add_edge(x,y,i-j,1);
			mcf.add_edge(y,x,j,1);
		}
		else {
			def += j-i;
			mcf.add_edge(y,x,j-i,0);
			mcf.add_edge(y,x,i,1);
		}
		mcf.add_edge(x,y,1<<30,2);
	}
	FOR(i,N) {
		if(out[i]>0) mcf.add_edge(i,N+1,out[i],0);
		if(out[i]<0) mcf.add_edge(N,i,-out[i],0);
	}
	cout<<def + mcf.mincost(N,N+1).second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}