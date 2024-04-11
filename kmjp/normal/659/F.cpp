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
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int H,W;
ll K;
int A[1010][1010];
UF<1010101> uf;

void dfs(int y,int x,int v) {
	int i;
	if(K<=0) return;
	K--;
	A[y][x]=v;
	
	FOR(i,4) {
		int dd[4]={1,0,-1,0};
		int ty=y+dd[i];
		int tx=x+dd[i^1];
		if(tx<0 || tx>=W || ty<0|| ty>=H) continue;
		if(A[ty][tx]) continue;
		if(uf[ty*1000+tx]!=uf[y*1000+x]) continue;
		if(K<=0) return;
		dfs(ty,tx,v);
		if(K<=0) return;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K;
	
	vector<pair<int,int>> V;
	FOR(y,H) FOR(x,W) {
		cin>>A[y][x];
		V.push_back({-A[y][x],y*1000+x});
	}
	sort(ALL(V));
	FORR(r,V) {
		y=r.second/1000;
		x=r.second%1000;
		int id=y*1000+x;
		
		if(y&&A[y-1][x]>=A[y][x]) uf(id-1000,id);
		if(y<H-1&&A[y+1][x]>=A[y][x]) uf(id+1000,id);
		if(x&&A[y][x-1]>=A[y][x]) uf(id-1,id);
		if(x<W-1&&A[y][x+1]>=A[y][x]) uf(id+1,id);
		
		if(K%A[y][x]==0 && (ll)A[y][x]*uf.count(id)>=K) {
			i=A[y][x];
			ZERO(A);
			K/=i;
			dfs(y,x,i);
			_P("YES\n");
			FOR(y,H) FOR(x,W) _P("%d%s",A[y][x],(x==W-1)?"\n":" ");
			return;
		}
	}
	_P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}