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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

int N,M;
int U[202020],V[202020],C[202020],used[202020];

vector<int> E[200005];
int P[21][200005],D[200005],ma[21][200005];
map<pair<int,int>,int> EE;
vector<int> add[200005];
vector<int> del[200005];
multiset<int> L[202020];
int ret[202020];

void dfs(int cur,int pre,int dep) {
	P[0][cur]=pre;
	D[cur]=dep;
	if(cur) ma[0][cur]=C[EE[{cur,pre}]];
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,dep+1);
}
void dfs2(int cur,int pre) {
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		if(L[cur].size()<L[e].size()) swap(L[cur],L[e]);
		FORR(r,L[e]) L[cur].insert(r);
		L[e].clear();
	}
	FORR(r,add[cur]) L[cur].insert(r);
	FORR(r,del[cur]) L[cur].erase(L[cur].find(r));
	
	if(pre!=-1) {
		if(L[cur].empty()) ret[EE[{cur,pre}]]=-1;
		else ret[EE[{cur,pre}]]=*L[cur].begin()-1;
	}
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	priority_queue<pair<int,int>> Q;
	FOR(i,M) {
		cin>>U[i]>>V[i]>>C[i];
		U[i]--,V[i]--;
		Q.push({-C[i],i});
		EE[{U[i],V[i]}]=EE[{V[i],U[i]}]=i;
	}
	
	while(Q.size()) {
		int co=-Q.top().first;
		int id=Q.top().second;
		Q.pop();
		if(uf[U[id]]!=uf[V[id]]) {
			E[U[id]].push_back(V[id]);
			E[V[id]].push_back(U[id]);
			used[id]=1;
			uf(U[id],uf[V[id]]);
		}
	}
	dfs(0,0,0);
	FOR(i,19) FOR(x,N) {
		P[i+1][x]=P[i][P[i][x]];
		ma[i+1][x]=max(ma[i][x],ma[i][P[i][x]]);
	}
	FOR(i,M) if(used[i]==0) {
		int u=U[i],v=V[i],r=lca(u,v);
		if(U[i]!=r) {
			add[U[i]].push_back(C[i]);
			del[r].push_back(C[i]);
		}
		if(V[i]!=r) {
			add[V[i]].push_back(C[i]);
			del[r].push_back(C[i]);
		}
		
		for(j=19;j>=0;j--) {
			if(D[u]-D[r]>=1<<j) ret[i]=max(ret[i],ma[j][u]-1), u=P[j][u];
			if(D[v]-D[r]>=1<<j) ret[i]=max(ret[i],ma[j][v]-1), v=P[j][v];
		}
	}
	dfs2(0,-1);
	
	FOR(i,M) cout<<ret[i]<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}