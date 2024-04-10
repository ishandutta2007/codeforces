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
	struct edge { int to; V capacity; V cost; int reve; int id;};
	vector<edge> E[NV]; int prev_v[NV], prev_e[NV]; V dist[NV];
	void add_edge(int x,int y, V cap, V cost, int id=-1) {
		E[x].push_back((edge){y,cap,cost,(int)E[y].size(),id});
		E[y].push_back((edge){x,0, -cost,(int)E[x].size()-1,-1}); /* rev edge */
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
			
			if(dist[to]>=0) return 1LL<<60;
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

MinCostFlow<23050,ll> mcf;

int N1,N2,M,R,B;
string C[2];
vector<pair<int,int>> E[2][202];
pair<int,int> P[202];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N1>>N2>>M>>R>>B;
	cin>>C[0]>>C[1];
	ll diff=0;
	int in=0,out=0;
	FOR(i,N1) {
		
		if(C[0][i]=='R') {
			mcf.add_edge(0,1+i,1,-(1<<30)), diff++,in++;
			mcf.add_edge(0,1+i,500,0);
		}
		else if(C[0][i]=='B') {
			mcf.add_edge(1+i,1000,1,-(1<<30)), diff++,out++;
			mcf.add_edge(1+i,1000,500,0);
		}
		else {
			mcf.add_edge(0,1+i,500,0);
			mcf.add_edge(1+i,1000,500,0);
		}
	}
	FOR(i,N2) {
		if(C[1][i]=='R') {
			mcf.add_edge(300+i,1000,1,-(1<<30)), diff++,out++;
			mcf.add_edge(300+i,1000,500,0);
		}
		else if(C[1][i]=='B') {
			mcf.add_edge(0,300+i,1,-(1<<30)), diff++,in++;
			mcf.add_edge(0,300+i,1000,0);
		}
		else {
			mcf.add_edge(0,300+i,500,0);
			mcf.add_edge(300+i,1000,500,0);
		}
	}
	
	FOR(i,M) {
		cin>>P[i].first>>P[i].second;
		P[i].first--;
		P[i].second--;
		mcf.add_edge(1+P[i].first,300+P[i].second,1,R,i);
		mcf.add_edge(300+P[i].second,1+P[i].first,1,B,i);
	}
	
	ll ret=diff<<30;
	while(1) {
		ll pat=mcf.mincost(0,1000,1);
		if(pat>0) break;
		ret+=pat;
	}
	
	if(ret>1LL<<29) {
		cout<<-1<<endl;
	}
	else {
		
		cout<<ret<<endl;
		string S(M,'U');
		FOR(i,N1) FORR(e,mcf.E[1+i]) if(e.id>=0 && e.capacity==0) S[e.id]='R';
		FOR(i,N2) FORR(e,mcf.E[300+i]) if(e.id>=0 && e.capacity==0) S[e.id]='B';
		cout<<S<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}