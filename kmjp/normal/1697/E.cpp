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


int N;
ll X[101],Y[101];
const ll mo=998244353;

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
UF<101> uf;

ll from[201],to[201];
int D[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(x,N) FOR(y,N) D[x][y]=abs(X[x]-X[y])+abs(Y[x]-Y[y]);
	
	FOR(i,N) FOR(j,i) FOR(k,j) if(D[i][j]==D[i][k]&&D[i][j]==D[j][k]) {
		FOR(x,N) if(x!=i&&x!=j&&x!=k&&(D[x][i]<=D[i][j]||D[x][j]<=D[i][j]||D[x][k]<=D[i][j])) break;
		if(x==N) {
			uf(i,j);
			uf(i,k);
		}
	}
	FOR(i,N) FOR(j,i) FOR(k,j) if(D[i][j]==D[i][k]&&D[i][j]==D[j][k]) FOR(x,k) {
		if(D[i][j]==D[x][i]&&D[i][j]==D[x][j]&&D[i][j]==D[x][k]) {
			FOR(y,N) if(y!=i&&y!=j&y!=k&&y!=x&&(D[y][i]<=D[i][j]||D[y][j]<=D[i][j]||D[y][k]<=D[i][j]||D[y][x]<=D[i][j])) break;
			if(y==N) {
				uf(i,j);
				uf(i,k);
				uf(i,x);
			}
		}
	}

	FOR(i,N) FOR(j,i) {
		FOR(k,N) if(k!=i&&k!=j&&(D[k][i]<=D[i][j]||D[k][j]<=D[i][j])) break;
		if(k==N) uf(i,j);
	}
	
	
	from[0]=1;
	FOR(i,N) if(uf[i]==i) {
		x=uf.count(i);
		ZERO(to);
		FOR(j,N+1) {
			if(x>1) (to[j+x]+=from[j])%=mo;
			(to[j+1]+=from[j])%=mo;
		}
		swap(from,to);
	}
	ll ret=0;
	for(i=1;i<=N;i++) {
		ll pat=from[i];
		FOR(j,i) pat=pat*(N-j)%mo;
		ret+=pat;
	}
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}