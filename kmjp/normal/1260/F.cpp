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

int N;
ll L[101010],R[101010],D[101010],G[101010];
vector<int> add[101010],del[101010];
vector<int> E[101010];
const ll mo=1000000007;

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

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) {
			(bit[0][entry-1]+=val0)%=mo;
			(bit[1][entry-1]+=val1)%=mo;
			entry += entry & -entry;
		}
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		v0%=mo;
		v1%=mo;
		return ((e*v0+v1)%mo+mo)%mo;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		val%=mo;
		update(L,val,((-val*(L-1))%mo+mo)%mo);
		update(R+1,mo-val,(val*R%mo+mo)%mo);
	}
};
BIT_r<ll,20> bt;

HLdecomp hl;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

void doadd(int f,ll v) {
	while(hl.B[f]) {
		bt.add(hl.L[hl.B[f]],hl.L[f],v);
		f=hl.P[0][hl.B[f]];
	}
	bt.add(0,hl.L[f],v);
}
ll get(int f) { // ft
	ll ret=0;
	while(hl.B[f]) {
		ret += bt.total(hl.L[f])-bt.total(hl.L[hl.B[f]]-1);
		f=hl.P[0][hl.B[f]];
	}
	ret += bt.total(hl.L[f])-bt.total(0);
	return (ret%mo+mo)%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	hl.init(N);
	ll P=1;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		add[L[i]].push_back(i);
		del[R[i]].push_back(i);
		G[i]=R[i]-L[i]+1;
		P=P*G[i]%mo;
		G[i]=modpow(G[i]);
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		hl.add_edge(x-1,y-1);
	}
	hl.decomp();
	FOR(i,N) D[i]=hl.D[i];
	
	ll ret=0;
	ll sum1d=0,sum1=0,sum2=0,sum3=0;
	for(int c=1;c<=100000;c++) {
		FORR(v,add[c]) {
			(sum1d+=D[v]*G[v])%=mo;
			(sum1+=G[v])%=mo;
			(sum2+=D[v]*G[v]%mo*G[v])%=mo;
			(sum3+=get(v)*G[v])%=mo;
			doadd(v,G[v]);
		}
		//cout<<sum3<<endl;
		ret+=sum1d*sum1-sum2-2*sum3;
		ret=(ret%mo+mo)%mo;
		
		FORR(v,del[c]) {
			(sum1d+=mo-D[v]*G[v]%mo)%=mo;
			(sum1+=mo-G[v]%mo)%=mo;
			(sum2+=mo-D[v]*G[v]%mo*G[v]%mo)%=mo;
			doadd(v,mo-G[v]);
			(sum3+=mo-get(v)*G[v]%mo)%=mo;
		}
	}
	cout<<ret*P%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}