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

int T,N,M;

class SCC {
public:
	static const int MV = 2025000;
	vector<vector<int> > SC; int NV,GR[MV];
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x); }
	void dfs(int cu) { vis[cu]=1; for(int i=0;i<E[cu].size();i++) if(!vis[E[cu][i]]) dfs(E[cu][i]); NUM.push_back(cu); }
	void revdfs(int cu, int ind) { int i; vis[cu]=1; GR[cu]=ind; SC[ind].push_back(cu);
		FOR(i,RE[cu].size()) if(!vis[RE[cu][i]]) revdfs(RE[cu][i],ind);}
	void scc() {
		int c=0,i; SC.clear(); SC.resize(NV); NUM.clear();
		assert(NV);
		FOR(i,NV) vis[i]=0; FOR(i,NV) if(!vis[i]) dfs(i); FOR(i,NV) vis[i]=0;
		for(int i=NUM.size()-1;i>=0;i--) if(!vis[NUM[i]]){
			SC[c].clear(); revdfs(NUM[i],c); sort(SC[c].begin(),SC[c].end()); c++;
		}
		SC.resize(c);
	}
};
SCC scc;
int ret[804040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		scc.init(2*N);
		FOR(i,2*N) ret[i]=0;
		FOR(i,M) {
			cin>>x>>y;
			x--,y--;
			if(x==y) {
				scc.add_edge(x,x+N);
				scc.add_edge(x+N,x);
			}
			else {
				scc.add_edge(x,y);
			}
		}
		scc.scc();
		ret[scc.GR[0]]=1;
		FOR(i,scc.SC.size()) {
			if(scc.SC[i].size()>1&&ret[i]>0) ret[i]=3;
			if(ret[i]==0) continue;
			
			FORR(cur,scc.SC[i]) {
				FORR(e,scc.E[cur]) {
					x=scc.GR[e];
					if(x!=i) {
						if(ret[i]==1&&ret[x]==1) ret[x]=2;
						else ret[x]=max(ret[x],ret[i]);
					}
				}
			}
			if(ret[i]==3) ret[i]=-1;
		}
		
		FOR(i,N) cout<<ret[scc.GR[i]]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}