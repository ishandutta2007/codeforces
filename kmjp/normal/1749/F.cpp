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
	int getpar(int cur,int up) {
		int i;
		FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
		return cur;
	}
	void decomp(int root=0){
		assert(NE==N-1);
		dfs(root,root); dfs2(root,root);
		int i,x; FOR(i,MD) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	}
};

HLdecomp hl;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt[21],sub[21];
int N,Q;

void doset(int f,int t,int order,int v) {
	while(hl.B[f]!=hl.B[t]) {
		bt[order].add(hl.L[hl.B[f]],v);
		bt[order].add(hl.L[f]+1,-v);
		f=hl.P[0][hl.B[f]];
	}
	bt[order].add(hl.L[t],v);
	bt[order].add(hl.L[f]+1,-v);
}
void doset2(int f,int t,int order,int v) {
	while(hl.B[f]!=hl.B[t]) {
		sub[order].add(hl.L[hl.B[f]],v);
		sub[order].add(hl.L[f]+1,-v);
		f=hl.P[0][hl.B[f]];
	}
	sub[order].add(hl.L[t],v);
	sub[order].add(hl.L[f]+1,-v);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	hl.init(N);
	FOR(i,N-1) {
		cin>>x>>y;
		hl.add_edge(x-1,y-1);
	}
	hl.decomp();
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		int U,V,K,D;
		if(i==1) {
			cin>>V;
			V--;
			ll sum=0;
			ll pre[21]={};
			for(i=0;i<=20;i++) {
				for(j=i;j<=20;j++) {
					//cout<<"#"<<j<<" "<<bt[j](hl.L[V])<<" "<<pre[j]<<endl;
					sum+=bt[j](hl.L[V])-pre[j];
					pre[j]=sub[j](hl.L[V]);
				}
				//cout<<i<<" "<<V<<" "<<sum<<endl;
				if(V==0) break;
				V=hl.P[0][V];
			}
			cout<<sum<<endl;
		}
		else {
			cin>>U>>V>>K>>D;
			U--,V--;
			int lc=hl.lca(U,V).first;
			
			doset(U,lc,D,K);
			doset(V,lc,D,K);
			bt[D].add(hl.L[lc],-K);
			bt[D].add(hl.L[lc]+1,K);
			doset2(U,lc,D,K);
			doset2(V,lc,D,K);
			sub[D].add(hl.L[lc],-2*K);
			sub[D].add(hl.L[lc]+1,2*K);
			
			for(i=1;i<=D;i++) {
				if(lc==0) break;
				x=hl.P[0][lc];
				bt[D-i].add(hl.L[x],K);
				bt[D-i].add(hl.L[x]+1,-K);
				sub[D-i].add(hl.L[lc],K);
				sub[D-i].add(hl.L[lc]+1,-K);
				lc=x;
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