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
int ret;
int A[2020];

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
UF<2050> uf;

int check() {
	uf.reinit(N+30);
	int i,j;
	FOR(i,N) FOR(j,30) if(A[i]&(1<<j)) uf(i,N+j);
	FOR(i,N) if(uf[i]!=uf[0]) return 0;
	cout<<ret<<endl;
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
	return 1;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		ret=0;
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
			if(A[i]==0) {
				ret++;
				A[i]++;
			}
		}
		if(check()) continue;
		ret++;
		int msb=0;
		FOR(i,N) {
			msb=max(msb,(-A[i])&A[i]);
			A[i]++;
			if(check()) break;
			A[i]-=2;
			if(check()) break;
			A[i]++;
		}
		if(i<N) continue;
		ret++;
		FOR(i,N) if(((-A[i])&A[i])==msb) {
			A[i]++;
			break;
		}
		FOR(i,N) if(((-A[i])&A[i])==msb) {
			A[i]--;
			break;
		}
		check();
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}