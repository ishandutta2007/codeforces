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

int N,M,Q;
int U[505050],V[505050],W[505050],need[505050];
vector<int> E[505050];

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2];
			par[a[3]]=a[4]; rank[a[3]]=a[5];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],y,par[y],rank[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
	}
};
UF_pop<500001> uf;
map<int,vector<int>> ev[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,M) {
		scanf("%d%d%d",&U[i],&V[i],&W[i]);
		U[i]--;
		V[i]--;
		E[W[i]].push_back(i);
	}
	scanf("%d",&Q);
	FOR(i,Q) {
		int NN;
		scanf("%d",&NN);
		need[i]=1;
		while(NN--) {
			scanf("%d",&x);
			x--;
			ev[W[x]][i].push_back(x);
		}
	}
	
	for(int w=1;w<=500000;w++) {
		FORR(MM,ev[w]) {
			x=MM.first;
			auto VV=MM.second;
			
			
			FORR(r,VV) {
				if(uf[U[r]]==uf[V[r]]) need[x]=0;
				uf(U[r],V[r]);
			}
			FOR(i,VV.size()) uf.pop();
		}
		
		FORR(r,E[w]) if(U[r]!=V[r]) uf(U[r],V[r]);
	}
	
	FOR(i,Q) {
		if(need[i]) _P("YES\n");
		else _P("NO\n");
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}