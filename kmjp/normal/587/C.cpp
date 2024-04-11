#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q;
vector<int> E[101010];
vector<int> T[101010];
int C[101010];

struct order {
	int v[10];
};

order def;

order comb(order a,order b) {
	order o;
	int i,aa=0,bb=0;
	FOR(i,10) {
		if(a.v[aa]==b.v[bb]) o.v[i]=a.v[aa++], bb++;
		else if(a.v[aa]<b.v[bb]) o.v[i]=a.v[aa++];
		else o.v[i]=b.v[bb++];
	}
	return o;
}

struct HLdecomp {
	static const int MD=20;
	int N,NE;
	vector<vector<int>> E,Cs; // edge, list of BIT
	vector<int> D,S,B,C,Ci; // depth, size, base of BIT, child of BIT(val,id)
	vector<vector<int>> P;
	void init(int N) { this->N=N, NE=0, E.clear(),E.resize(N); Cs.clear(),Cs.resize(N);
		D=S=B=C=Ci=vector<int>(N,0); int i; P.clear(); FOR(i,MD+1) P.push_back(vector<int>(N,0));}
	void add_edge(int a,int b){ E[a].push_back(b),E[b].push_back(a); NE++;} // undir
	void dfs(int cur,int pre) { // get depth, parent, size, largest subtree
		int i;
		P[0][cur]=pre;S[cur]=1;C[cur]=Ci[cur]=-1;B[cur]=cur;
		D[cur]=(pre==-1)?0:(D[pre]+1);
		FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
			int r=E[cur][i]; dfs(r,cur); S[cur]+=S[r];
			if(C[cur]==-1 || S[r]>S[C[cur]]) C[cur]=r,Ci[cur]=i;
		}
	}
	void dfs2(int cur,int pre) { // set base and list
		if(pre!=-1 && C[pre]==cur) B[cur]=B[pre];
		Cs[B[cur]].push_back(cur);
		FORR(r,E[cur]) if(r!=pre) dfs2(r,cur);
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

class SegTree {
public:
	int NV;
	vector<order> base;
	
	void init(int n) {
		NV=1;
		while(NV<=n) NV*=2;
		base.resize(NV*2,def);
	}
	
	void build() {
		int i;
		for(i=NV-1;i>=1;i--) base[i]=comb(base[2*i],base[2*i+1]);
	}

	order getval(int x,int y,int l=0,int r=-1,int k=1) {
		if(r==-1) r=NV;
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return base[k];
		x=max(x,l); y=min(y,r);
		return comb(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}

};

HLdecomp hl;
SegTree st[201010];

order get(int f,int t) {
	order ret = def;
	while(hl.B[f]!=hl.B[t]) {
		ret = comb(ret,st[hl.B[f]].getval(0,1+hl.D[f]-hl.D[hl.B[f]]));
		f=hl.P[0][hl.B[f]];
	}
	ret = comb(ret,st[hl.B[f]].getval(hl.D[t]-hl.D[hl.B[f]],1+hl.D[f]-hl.D[hl.B[f]]));
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	hl.init(N);
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		hl.add_edge(x-1,y-1);
	}
	FOR(i,M) {
		cin>>x;
		T[x-1].push_back(i+1);
	}
	hl.decomp();
	FOR(x,10) def.v[x]=999999;
	FOR(i,N) if(hl.B[i]==i) st[i].init(hl.Cs[i].size()+2);
	FOR(i,N) {
		FOR(x,10) T[i].push_back(999999);
		sort(ALL(T[i]));
		FOR(x,10) st[hl.B[i]].base[st[hl.B[i]].NV+hl.D[i]-hl.D[hl.B[i]]].v[x]=T[i][x];
	}
	FOR(i,N) if(hl.B[i]==i) st[i].build();
	
	while(Q--) {
		int U,V,A;
		cin>>U>>V>>A;
		U--,V--;
		auto lca=hl.lca(U,V).first;
		auto o1=get(U,lca);
		auto o2=get(V,lca);
		
		auto o3=comb(o1,o2);
		FOR(x,A) if(o3.v[x]>100000) break;
		_P("%d",x);
		FOR(i,x) _P(" %d",o3.v[i]);
		_P("\n");
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}