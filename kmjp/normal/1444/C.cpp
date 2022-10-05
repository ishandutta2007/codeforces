#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


int N,M,K;
int C[505050];
vector<int> cand[505050];
map<pair<int,int>,vector<pair<int,int>>> Scand;

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; hist.clear(); FOR(i,um) rank[i]=0,par[i]=i;}
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
UF_pop<1010101> uf;
int NG[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&K);
	FOR(i,N) {
		scanf("%d",&C[i]);
		C[i]--;
		cand[C[i]].push_back(i);
	}
	
	FOR(i,M) {
		scanf("%d%d",&x,&y);
		x--,y--;
		if(C[x]==C[y]) {
			uf(2*x,2*y+1);
			uf(2*y,2*x+1);
		}
		else {
			if(C[x]>C[y]) swap(x,y);
			Scand[{C[x],C[y]}].push_back({x,y});
		}
	}
	
	ll ret=0;
	int okK=K;
	FOR(i,K) {
		FORR(c,cand[i]) {
			if(uf[2*c]==uf[2*c+1]) NG[i]=1;
		}
		if(NG[i]) okK--;
	}
	ret=1LL*okK*(okK-1)/2;
	
	FORR(m,Scand) {
		x=m.first.first;
		y=m.first.second;
		if(NG[x]||NG[y]) continue;
		int ng=0;
		FORR(v,m.second) {
			uf(v.first*2,v.second*2+1);
			uf(v.first*2+1,v.second*2);
			if(uf[v.first*2]==uf[v.first*2+1]) ng=1;
		}
		if(ng) ret--;
		FORR(v,m.second) uf.pop(), uf.pop();
	}
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}