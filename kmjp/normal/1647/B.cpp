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

int T,H,W;
string S[101];

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

int L[101][101];
int R[101][101];
int U[101][101];
int D[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		UF<10101> uf;
		cin>>H>>W;
		FOR(y,H) cin>>S[y];
		FOR(y,H) FOR(x,W) if(S[y][x]=='1') {
			if(x&&S[y][x-1]=='1') uf(y*100+x,y*100+x-1);
			if(y&&S[y-1][x]=='1') uf(y*100+x,y*100+x-100);
		}
		FOR(y,H) FOR(x,W) {
			L[y][x]=U[y][x]=101;
			R[y][x]=D[y][x]=-1;
		}
		FOR(y,H) FOR(x,W) {
			int ty=uf[y*100+x]/100;
			int tx=uf[y*100+x]%100;
			chmin(L[ty][tx],x);
			chmax(R[ty][tx],x);
			chmin(U[ty][tx],y);
			chmax(D[ty][tx],y);
		}
		int ok=1;
		FOR(y,H) FOR(x,W) if(uf[y*100+x]==y*100+x) {
			k=(R[y][x]-L[y][x]+1)*(D[y][x]-U[y][x]+1);
			if(k!=uf.count(y*100+x)) ok=0;
		}
		if(ok) {
			cout<<"Yes"<<endl;
		}
		else {
			cout<<"No"<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}