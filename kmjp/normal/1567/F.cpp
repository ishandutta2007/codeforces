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

int H,W;
string S[505];

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
UF<505*505> uf;

int ret[505][505];

void dfs(int y,int x,int v) {
	if(ret[y][x]) {
		return;
	}
	ret[y][x]=v;
	if(x&&S[y][x-1]=='.') dfs(y,x-1,5-v);
	if(x+1<W&&S[y][x+1]=='.') dfs(y,x+1,5-v);
	if(y&&S[y-1][x]=='.') dfs(y-1,x,v);
	if(y+1<H&&S[y+1][x]=='.') dfs(y+1,x,v);
	int dy[8]={2,1,1,0,0,-1,-1,-2};
	int dx[8]={0,1,-1,2,-2,1,-1,0};
	int i;
	FOR(i,8) {
		int ty=y+dy[i];
		int tx=x+dx[i];
		if(ty<0||ty>=H||tx<0||tx>=W) continue;
		if(S[ty][tx]=='X') continue;
		if(uf[y*W+x]==uf[ty*W+tx]) {
			if(abs(tx-x)%2) dfs(ty,tx,5-v);
			else dfs(ty,tx,v);
		}
		else {
			dfs(ty,tx,5-v);
		}
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) cin>>S[y];
	FOR(y,H) FOR(x,W) if(S[y][x]=='X') {
		int num=0;
		if(S[y-1][x]=='.') num++;
		if(S[y+1][x]=='.') num++;
		if(S[y][x-1]=='.') num++;
		if(S[y][x+1]=='.') num++;
		if(num%2) {
			cout<<"NO"<<endl;
			return;
		}
		ret[y][x]=5*num/2;
	}
	FOR(y,H) FOR(x,W) if(S[y][x]=='.') {
		if(y&&S[y-1][x]=='.') uf(y*W+x,(y-1)*W+x);
		if(x&&S[y][x-1]=='.') uf(y*W+x,y*W+x-1);
		if(x) {
			if(y&&S[y-1][x-1]=='.') uf(y*W+x,(y-1)*W+x-1);
			if(y+1<H&&S[y+1][x-1]=='.') uf(y*W+x,(y+1)*W+x-1);
		}
	}
	FOR(y,H) FOR(x,W) if(S[y][x]=='.'&&ret[y][x]==0) dfs(y,x,(x%2==0)?1:4);
	cout<<"YES"<<endl;
	FOR(y,H) {
		FOR(x,W) cout<<ret[y][x]<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}