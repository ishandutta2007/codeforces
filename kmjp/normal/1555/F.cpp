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


int N,Q;
int U[505050],V[505050],X[505050];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit(int num=um) {int i; FOR(i,num) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<1<<21> uf;
int valid[1505050];
vector<pair<int,int>> E[1303030];
int C[1303030];

struct HLdecomp {
	static const int MD=20;
	int N,NE,id;
	vector<vector<int>> E;
	vector<int> D,S,B,C; // depth, size, base,heavy child
	
	vector<int> L,R,rev; // EulerTour
	vector<vector<int>> P,Cs; // parent for LCA,children
	void init(int N) { this->N=N, NE=0, E.clear(),E.resize(N); Cs.clear(),Cs.resize(N);
		D=S=B=C=L=R=rev=vector<int>(N,0); id=0; int i; P.clear(); FOR(i,MD+1) P.push_back(vector<int>(N,0));}
	void add_edge(int a,int b){ E[a].push_back(b),E[b].push_back(a); NE++;} // undir
	void dfs(int cur,int pre) { // get depth, parent, size, largest subtree
		int i;
		P[0][cur]=pre;S[cur]=1;C[cur]=-1;B[cur]=cur;
		D[cur]=(pre==cur)?0:(D[pre]+1);
		FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
			int r=E[cur][i]; dfs(r,cur); S[cur]+=S[r];
			if(C[cur]==-1 || S[r]>S[C[cur]]) C[cur]=r;
		}
	}
	void dfs2(int cur,int pre) { // set base and list
		if(pre!=cur && C[pre]==cur) B[cur]=B[pre];
		else B[cur]=cur;
		Cs[B[cur]].push_back(cur);
		L[cur]=id++;
		rev[L[cur]]=cur;
		// DFS
		if(C[cur]!=-1) dfs2(C[cur],cur);
		FORR(r,E[cur]) if(r!=pre && r!=C[cur]) dfs2(r,cur);
		R[cur]=id;
	}
	pair<int,int> lca(int a,int b) {
		int ret=0,i,aa=a,bb=b;
		if(D[aa]>D[bb]) swap(aa,bb);
		for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
		for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
		return make_pair((aa==bb)?aa:P[0][aa], D[a]+D[b]-2*D[(aa==bb)?aa:P[0][aa]]);
	}
	void decomp(int root=0){
		assert(NE==N-1);
		dfs(root,root); dfs2(root,root);
		int i,x; FOR(i,MD) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	}
};

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l || y<=x) return 0;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r||y<=x) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};

HLdecomp hl;
SegTree_3<int,1<<21> st;

void dfs(int cur,int pre,int v) {
	C[cur]=v;
	FORR2(e,x,E[cur]) if(e!=pre) dfs(e,cur,v^x);
}

void doset(int f,int t) {
	while(hl.B[f]!=hl.B[t]) {
		st.update(hl.L[hl.B[f]],hl.L[f]+1,1);
		f=hl.P[0][hl.B[f]];
	}
	st.update(hl.L[t]+1,hl.L[f]+1,1);
}
int get(int f,int t) { // ft
	int ret = 0;
	while(hl.B[f]!=hl.B[t]) {
		ret = max(ret,st.getval(hl.L[hl.B[f]],hl.L[f]+1));
		f=hl.P[0][hl.B[f]];
	}
	ret = max(ret,st.getval(hl.L[t]+1,hl.L[f]+1));
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	hl.init(N+1);
	FOR(i,Q) {
		scanf("%d%d%d",&U[i],&V[i],&X[i]);
		U[i]--;
		V[i]--;
		if(uf[U[i]]!=uf[V[i]]) {
			valid[i]=1;
			uf(U[i],V[i]);
			E[U[i]].push_back({V[i],X[i]});
			E[V[i]].push_back({U[i],X[i]});
			hl.add_edge(U[i],V[i]);
		}
	}
	FOR(i,N) if(uf[i]==i) {
		E[N].push_back({i,0});
		E[i].push_back({N,0});
		hl.add_edge(i,N);
	}
	dfs(N,N,0);
	hl.decomp(N);
	
	FOR(i,Q) {
		int u=U[i];
		int v=V[i];
		if(valid[i]==1) {
			_P("YES\n");
		}
		else if((C[u]^X[i])==C[v]) {
			_P("NO\n");
		}
		else {
			int lc=hl.lca(u,v).first;
			int ma=0;
			ma=max({get(u,lc),get(v,lc)});
			if(ma) {
				_P("NO\n");
			}
			else {
				doset(u,lc);
				doset(v,lc);
				_P("YES\n");
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}