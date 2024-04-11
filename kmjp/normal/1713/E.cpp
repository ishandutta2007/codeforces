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

int T,N;
int A[1010][1010];

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
UF<2010> uf;
int fix[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(y,N) FOR(x,N) cin>>A[y][x];
		uf.reinit(N*2);
		FOR(i,2*N) fix[i]=-1;
		
		FOR(y,N) FOR(x,N) if(x>y) {
			if(A[y][x]<A[x][y]) {
				if(uf[x*2+1]!=uf[y*2]) {
					uf(x*2,y*2);
					uf(x*2+1,y*2+1);
				}
			}
			if(A[y][x]>A[x][y]) {
				if(uf[x*2]!=uf[y*2]) {
					uf(x*2,y*2+1);
					uf(x*2+1,y*2);
				}
			}
		}
		
		FOR(i,N) if(fix[uf[i*2]]==-1) {
			if(fix[uf[i*2+1]]==0) {
				fix[uf[i*2]]=1;
			}
			else {
				fix[uf[i*2]]=0;
				fix[uf[i*2+1]]=1;
			}
		}
		
		FOR(i,N) if(fix[uf[i*2]]) {
			FOR(j,N) swap(A[i][j],A[j][i]);
		}
		FOR(y,N) {
			FOR(x,N) cout<<A[y][x]<<" ";
			cout<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}