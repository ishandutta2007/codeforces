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
int R[101010];
vector<int> E[101010];
vector<int> G[101010];
vector<int> P[101010];
int VV[101010];
int VE[101010];

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

int ok(int ce,int on,int pre,int id) ;
int ok2(int cv,int on,int pree,int id) {
	int tar=0;
	if(pree==P[cv][0]) tar++;
	
	if(VE[P[cv][tar]]<id) {
		return ok(P[cv][tar],on^R[cv],cv,id);
	}
	else {
		return ((VE[P[cv][tar]]==id+1) ^ on ^ R[cv])==0;
	}
	
}

int ok(int ce,int on,int pre,int id) {
	VE[ce]=id+on;
	FORR(v,E[ce]) if(v!=pre) {
		if(ok2(v,on,ce,id)==0) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>R[i], R[i]^=1;
	FOR(i,M) {
		cin>>x;
		FOR(j,x) {
			cin>>y;
			y--;
			E[i].push_back(y);
			P[y].push_back(i);
		}
	}
	
	FOR(i,N) uf(P[i][0],P[i][1]);
	
	MINUS(VE);
	FOR(i,M) if(uf[i]==i) {
		if(ok(i,0,-1,i*4)==0 && ok(i,1,-1,i*4+2)==0) return _P("NO\n");
	}
	return _P("YES\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}