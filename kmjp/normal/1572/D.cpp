#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,L,K;
int A[1<<20];
vector<pair<int,int>> B[2020202],E[101];
const int DI=100;
template<int NV,class V> class MinCostFlow {
public:
	struct edge { int to; V capacity; V cost; int reve;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV]; V pot[NV];
	void add_edge(int x,int y, V cap, V cost) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size()});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1}); /* rev edge */
	}
	
	V mincost(int from, int to, ll flow) {
		V res=0; int i,v;
		ZERO(prev_v); ZERO(prev_e); fill(pot, pot+NV, 0);
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
					if(e.capacity>0 && dist[e.to]>d+e.cost+pot[cur]-pot[e.to]) {
						dist[e.to]=d+e.cost+pot[cur]-pot[e.to];
						prev_v[e.to]=cur;
						prev_e[e.to]=i;
						Q.push(make_pair(-dist[e.to],e.to));
					}
				}
			}
			
			if(dist[to]==numeric_limits<V>::max()/2) return -1;
			V lc=flow;
			for(v=to;v!=from;v=prev_v[v]) lc = min(lc, E[prev_v[v]][prev_e[v]].capacity);
			FOR(i,NV) pot[i]+=dist[i];
			flow -= lc;
			res += lc*pot[to];
			for(v=to;v!=from;v=prev_v[v]) {
				edge &e=E[prev_v[v]][prev_e[v]];
				e.capacity -= lc;
				E[v][e.reve].capacity += lc;
			}
		}
		return res;
	}
};
MinCostFlow<(1<<20)+5,int> mcf;
int used[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	L=1<<N;
	FOR(i,L) scanf("%d",&A[i]);
	FOR(i,L) if(__builtin_popcount(i)%2==0) {
		FOR(x,N) {
			y=i^(1<<x);
			B[(A[i]+A[y])/DI].push_back({i,y});
		}
	}
	
	mcf.add_edge(1<<20,(1<<20)+1,K,2<<20);
	int lef=(2*N-1)*(K-1)+1;
	for(i=2020202/DI+1;i>=0;i--) if(lef>0) {
		FOR(j,DI) E[j].clear();
		FORR2(a,b,B[i]) E[(A[a]+A[b])%DI].push_back({a,b});
		for(j=DI-1;j>=0;j--) if(lef>=0) {
			FORR2(a,b,E[j]) {
				if(lef<=0) break;
				lef--;
				used[a]=used[b]=1;
				mcf.add_edge(a,b,1,(2<<20)-A[a]-A[b]);
			}
		}
		
	}
	FOR(i,L) if(used[i]) {
		if(__builtin_popcount(i)%2==0) {
			mcf.add_edge(1<<20,i,1,0);
		}
		else {
			mcf.add_edge(i,(1<<20)+1,1,0);
		}
	}
	ll ret=mcf.mincost(1<<20,(1<<20)+1,K);
	cout<<((2<<20)*K-ret)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}