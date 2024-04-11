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


int T,N,M;
vector<pair<int,int>> E[202020];

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

UF<404040> uf;
int X[202020],Y[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		uf.reinit(2*N);
		
		FOR(i,N-1) {
			cin>>X[i]>>Y[i]>>R[i];
			X[i]--;
			Y[i]--;
			if(R[i]>=0) {
				if(__builtin_popcount(R[i])%2==0) {
					uf(X[i],Y[i]);
					uf(N+X[i],N+Y[i]);
				}
				else {
					uf(X[i],N+Y[i]);
					uf(N+X[i],Y[i]);
				}
			}
		}
		FOR(i,M) {
			cin>>x>>y>>r;
			x--,y--;
			if(r==0) {
				uf(x,y);
				uf(N+x,N+y);
			}
			else {
				uf(x,N+y);
				uf(N+x,y);
			}
		}
		
		FOR(i,N) {
			if(uf[i]==uf[N+i]) {
				cout<<"NO"<<endl;
				break;
			}
		}
		if(i==N) {
			cout<<"YES"<<endl;
			FOR(i,N-1) {
				if(R[i]==-1) {
					if(uf[X[i]]!=uf[Y[i]] && uf[X[i]]!=uf[N+Y[i]]) {
						uf(X[i],Y[i]);
						uf(N+X[i],N+Y[i]);
					}
					if(uf[X[i]]==uf[Y[i]]) {
						R[i]=0;
					}
					else {
						R[i]=1;
					}
				}
				cout<<(X[i]+1)<<" "<<(Y[i]+1)<<" "<<R[i]<<endl;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}