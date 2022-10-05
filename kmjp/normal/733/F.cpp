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
ll W[202020],C[202020];
int A[202020],B[202020],used[202020];
vector<pair<int,int>> E[202020];
map<pair<int,int>,int> MP;
int P[21][200005],D[200005];
int mi[21][200005];
ll S;

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

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs(int cur) {
	ITR(it,E[cur]) if(it->first!=P[0][cur]) D[it->first]=D[cur]+1, P[0][it->first]=cur, dfs(it->first);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>W[i];
	FOR(i,M) cin>>C[i];
	priority_queue<pair<int,int>> PP;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--; B[i]--;
		PP.push({-W[i],i});
	}
	cin>>S;
	
	ll tot=0;
	int id=-1;
	
	while(PP.size()) {
		x = PP.top().second;
		PP.pop();
		if(uf[A[x]]!=uf[B[x]]) {
			used[x]=1;
			tot+=W[x];
			uf(A[x],B[x]);
			E[A[x]].push_back({B[x],x});
			E[B[x]].push_back({A[x],x});
			MP[{A[x],B[x]}]=MP[{B[x],A[x]}]=x;
		}
	}
	
	dfs(0);
	mi[0][0]=-1;
	for(i=1;i<N;i++) mi[0][i]=MP[{i,P[0][i]}];
	FOR(i,19) {
		FOR(x,N) {
			P[i+1][x]=P[i][P[i][x]];
			if(x==0) {
				mi[i+1][x]=-1;
			}
			else {
				if(P[i][x]==0) mi[i+1][x]=mi[i][x];
				else {
					int a = mi[i][x];
					int b = mi[i][P[i][x]];
					mi[i+1][x]=(W[a]>W[b])?a:b;
				}
			}
		}
	}
	
	ll best=1LL<<60;
	int del=-1,add=-1;
	FOR(i,M) {
		if(used[i]==1) {
			if(tot - S/C[i] < best) {
				best = tot - S/C[i];
				add = i;
				del = -1;
			}
		}
		else {
			int u=A[i], v=B[i], lc=lca(u,v);
			int be = -1;
			for(x=18;x>=0;x--) {
				if(D[u]-D[lc]>=1<<x) {
					y=mi[x][u];
					if(be==-1 || W[y]>W[be]) be=y;
					u=P[x][u];
				}
				if(D[v]-D[lc]>=1<<x) {
					y=mi[x][v];
					if(be==-1 || W[y]>W[be]) be=y;
					v=P[x][v];
				}
			}
			assert(be>=0);
			if(tot - W[be] + W[i]-S/C[i] < best) {
				best = tot - W[be] + W[i]-S/C[i];
				add = i;
				del = be;
			}
		}
	}
	
	cout<<best<<endl;
	FOR(i,M) {
		if(i==add || (used[i]&&del!=i)) {
			cout<<(i+1)<<" ";
			if(i==add) cout<<W[i]-S/C[i]<<endl;
			else cout<<W[i]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}