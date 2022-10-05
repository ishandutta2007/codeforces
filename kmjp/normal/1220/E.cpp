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

int N,M;
int W[202020];
int U[402020],V[402020];

class SCC_BI {
public:
	static const int MV = 210000;
	int NV,time;
	vector<vector<int> > E;
	vector<int> ord,llink,inin;
	stack<int> roots,S;
	vector<int> M; //point to group
	vector<int> ART; // out
	vector<vector<int> > SC; // out
	vector<pair<int,int> > BR; // out
	
	void init(int NV=MV) { this->NV=NV; E.clear(); E.resize(NV);}
	void add_edge(int x,int y) { assert(NV); E[x].push_back(y); E[y].push_back(x); }
	void dfs(int cur,int pre) {
		int art=0,conn=0,i,se=0;
		ord[cur]=llink[cur]=++time;
		S.push(cur); inin[cur]=1; roots.push(cur);
		FOR(i,E[cur].size()) {
			int tar=E[cur][i];
			if(ord[tar]==0) {
				conn++; dfs(tar,cur);
				llink[cur]=min(llink[cur],llink[tar]);
				art += (pre!=-1 && ord[cur]<=llink[tar]);
				if(ord[cur]<llink[tar]) BR.push_back(make_pair(min(cur,tar),max(cur,tar)));
			}
			else if(tar!=pre || se) {
				llink[cur]=min(llink[cur],ord[tar]);
				while(inin[tar]&&ord[roots.top()]>ord[tar]) roots.pop();
			}
			else se++; // double edge
		}
		
		if(cur==roots.top()) {
			SC.push_back(vector<int>());
			while(1) {
				i=S.top(); S.pop(); inin[i]=0;
				SC.back().push_back(i);
				M[i]=SC.size()-1;
				if(i==cur) break;
			}
			sort(SC.back().begin(),SC.back().end());
			roots.pop();
		}
		if(art || (pre==-1&&conn>1)) ART.push_back(cur);
	}
	void scc() {
		SC.clear(),BR.clear(),ART.clear(),M.resize(NV);
		ord.clear(),llink.clear(),inin.clear(),time=0;
		ord.resize(NV);llink.resize(NV);inin.resize(NV);
		for(int i=0;i<NV;i++) if(!ord[i]) dfs(i,-1);
		sort(BR.begin(),BR.end()); sort(ART.begin(),ART.end());
	}
};

SCC_BI bi,bi2;
template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<202020> uf;
int S;
int mp[202020];
ll W2[202020];
vector<int> E[202020];
ll ret,fix;
void dfs(int cur,int pre,ll tot) {
	tot+=W2[cur];
	ret=max(ret,tot);
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,tot);
}

int dfs1(int cur,int pre) {
	int ok=0;
	if(bi2.SC[cur].size()>1) ok=1;
	FORR(e,E[cur]) if(e!=pre) ok |= dfs1(e,cur);
	if(ok) {
		fix+=W2[cur];
		W2[cur]=0;
	}
	return ok;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) scanf("%d",&W[i]);
	bi.init(N);
	bi2.init(N);
	FOR(i,M) {
		scanf("%d%d",&U[i],&V[i]);
		U[i]--,V[i]--;
		uf(U[i],V[i]);
		bi.add_edge(U[i],V[i]);
		bi2.add_edge(U[i],V[i]);
	}
	scanf("%d",&S);
	S--;
	bi.scc();
	int pre=-1;
	FOR(i,bi.SC.size()) if(bi.SC[i].size()>1 && uf[S]==uf[bi.SC[i][0]]) {
		if(pre!=-1) {
			U[M]=pre;
			V[M]=bi.SC[i][0];
			bi2.add_edge(U[M],V[M]);
			M++;
		}
		pre=bi.SC[i][0];
	}
	bi2.scc();
	FOR(i,bi2.SC.size()) {
		FORR(r,bi2.SC[i]) {
			mp[r]=i;
			W2[i]+=W[r];
		}
	}
	FOR(i,M) {
		if(mp[U[i]]!=mp[V[i]]) {
			E[mp[U[i]]].push_back(mp[V[i]]);
			E[mp[V[i]]].push_back(mp[U[i]]);
		}
	}
	dfs1(mp[S],-1);
	dfs(mp[S],-1,0);
	cout<<ret+fix<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}