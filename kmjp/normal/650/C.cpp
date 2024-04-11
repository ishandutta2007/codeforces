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

int H,W;
vector<vector<int>> A,R;
vector<int> C[1010101];
int MX[1010101];
int MY[1010101];

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
UF<1100000> uf;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	A.resize(H);
	R.resize(H);
	FOR(y,H) {
		A[y].resize(W);
		R[y].resize(W);
		FOR(x,W) cin>>A[y][x];
	}
	
	FOR(y,H) {
		vector<pair<int,int>> T;
		FOR(x,W) T.push_back({A[y][x],x});
		sort(ALL(T));
		FOR(i,W-1) if(T[i].first==T[i+1].first) uf(y*W+T[i].second,y*W+T[i+1].second);
	}
	FOR(x,W) {
		vector<pair<int,int>> T;
		FOR(y,H) T.push_back({A[y][x],y});
		sort(ALL(T));
		FOR(i,H-1) if(T[i].first==T[i+1].first) uf(T[i].second*W+x,T[i+1].second*W+x);
	}
	
	vector<pair<int,int>> V;
	FOR(y,H) FOR(x,W) {
		if(uf[y*W+x]==y*W+x) V.push_back({A[y][x],y*W+x});
		C[uf[y*W+x]].push_back(y*W+x);
	}
	sort(ALL(V));
	FORR(r,V) {
		y=r.second/W;
		x=r.second%W;
		R[y][x]=1;
		FORR(r2,C[r.second]) R[y][x]=max(R[y][x],max(MY[r2/W]+1,MX[r2%W]+1));
		FORR(r2,C[r.second]) {
			R[r2/W][r2%W]=R[y][x];
			MY[r2/W]=max(MY[r2/W],R[y][x]);
			MX[r2%W]=max(MX[r2%W],R[y][x]);
		}
	}
	FOR(y,H) FOR(x,W) _P("%d%s",R[y][x],(x==W-1)?"\n":" ");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}