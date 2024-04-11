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

class SCC {
public:
	static const int MV = 2025000;
	vector<vector<int> > SC; int NV,GR[MV];
private:
	vector<int> E[MV], RE[MV], NUM; int vis[MV];
public:
	void init(int NV) { this->NV=NV; for(int i=0;i<NV;i++) { E[i].clear(); RE[i].clear();}}
	void add_edge(int x,int y) { E[x].push_back(y); RE[y].push_back(x);}
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

class TwoSat {
	int NV;
	SCC sc;
public:
	vector<int> val;
	void init(int NV) { this->NV=NV; sc.init(NV*2); val.resize(NV);}
	void add_edge(int x,int y) { // k+0:normal k+NV:inverse
		sc.add_edge((x+NV)%(2*NV),y%(2*NV));
		sc.add_edge((y+NV)%(2*NV),x%(2*NV));
	}
	void add_impl(int x,int xt,int y,int yt) { // xxtyyt
		//sc.add_edge(x+(xt?0:NV),y+(yt?0:NV)); <-
		add_or(x,!xt,y,yt);
	}
	void add_or(int x,int xt,int y,int yt) { // xt=1: x must be true
		add_edge(x+((!xt)?NV:0),y+((!yt)?NV:0));
	}
	void add_and(int x,int xt,int y,int yt) { // and
		add_or(x,xt,y,yt);
		add_or(x,!xt,y,yt);
		add_or(x,xt,y,!yt);
	}
	bool sat() { // empty:false 
		sc.scc();
		for(int i=0;i<NV;i++) if(sc.GR[i]==sc.GR[i+NV]) return false;
		for(int i=0;i<NV;i++) val[i]=sc.GR[i]>sc.GR[i+NV];
		return true;
	}
};

TwoSat ts;
int T,N,M,K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M>>K;
		ts.init(K*N);
		FOR(i,N) {
			ts.add_or(i*K,1,i*K,1);
			FOR(j,K-1) ts.add_impl(i*K+j+1,1,i*K+j,1);
			//
			if(i<N-1) {
				FOR(j,K) {
					ts.add_impl(i*K+j,1,(i+1)*K+j,1);
					ts.add_impl((i+1)*K+j,0,i*K+j,0);
				}
			}
		}
		while(M--) {
			cin>>x;
			if(x==1) {
				cin>>i>>x;
				i--;
				if(x==K) {
					ts.add_or(i*K+x-1,0,i*K+x-1,0);
				}
				else {
					ts.add_impl(i*K+x-1,1,i*K+x,1);
				}
				
			}
			else {
				cin>>i>>j>>y;
				i--,j--;
				for(k=1;k<=K;k++) {
					if(x==2) {
						int v=y-k+1;
						if(v<=k) ts.add_or(i*K+(k-1),0,i*K+(k-1),0);
						else if(v<=K) ts.add_impl(i*K+(k-1),1,j*K+(v-1),0);
							
					}
					else {
						int v=y-(k-1);
						if(v>K) ts.add_or(i*K+(k-1),1,i*K+(k-1),1);
						else if(v>=1) ts.add_impl(i*K+(k-1),0,j*K+(v-1),1);
					}
				}
			}
		}
		
		if(!ts.sat()) {
			cout<<-1<<endl;
		}
		else {
			FOR(i,N) {
				x=0;
				FOR(j,K) x+=ts.val[i*K+j];
				cout<<x<<" ";
			}
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}