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

int N,R[2];
vector<int> E[2][501];
int P[2][501];
int D[2][501];
int lim[2][501];
int limid[2][501];
int A[501];

template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; ll capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV];
	void add_edge(int x,int y, ll cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e);
		while(flow>0) {
			fill(dist, dist+NV, numeric_limits<V>::max()/2);
			dist[from]=0;
			priority_queue<pair<V,int> > Q;
			Q.push(make_pair(0,from));
			while(Q.size()) {
				V d=-Q.top().first;
				int cur=Q.top().second;
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
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
			ll lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			flow -= lc;
			res += lc*dist[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};
MinCostFlow<5050,ll> mcf;


void dfs(int id,int cur,int par) {
	P[id][cur]=par;
	D[id][cur]=D[id][par]+1;
	FORR(e,E[id][cur]) if(e!=par) dfs(id,e,cur);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>R[0]>>R[1];
	FOR(i,N) cin>>A[i+1];
	
	FOR(j,2) {
		FOR(i,N-1) {
			cin>>x>>y;
			E[j][x].push_back(y);
			E[j][y].push_back(x);
		}
		dfs(j,R[j],0);
	}
	
	int ma=0;
	FOR(j,2) {
		vector<pair<int,int>> cand;
		for(i=1;i<=N;i++) {
			lim[j][i]=-101010;
			if(i!=R[j]) cand.push_back({D[j][i],i});
		}
		cin>>x;
		FOR(i,x) {
			cin>>r>>y;
			lim[j][r]=y;
			limid[j][r]=r;
		}
		ma=max(ma,lim[j][R[j]]);
		
		sort(ALL(cand));
		FORR(c,cand) {
			x=c.second;
			y=P[j][x];
			while(lim[j][y]<0) y=P[j][y];
			if(lim[j][x]>0) {
				lim[j][y]-=lim[j][x];
				if(lim[j][y]<0) return _P("-1\n");
			}
			else {
				limid[j][x]=y;
			}
		}
	}
	
	for(i=1;i<=N;i++) {
		if(lim[0][i]>0) mcf.add_edge(0,i,lim[0][i],0);
		if(lim[1][i]>0) mcf.add_edge(3000+i,5000,lim[1][i],0);
		mcf.add_edge(limid[0][i],1000+i,1,0);
		mcf.add_edge(1000+i,2000+i,1,100000-A[i]);
		mcf.add_edge(2000+i,3000+limid[1][i],1,0);
	}
	
	ll ret=mcf.mincost(0,5000,ma);
	if(ret<0) {
		cout<<-1<<endl;
	}
	else {
		cout<<ma*100000-ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}