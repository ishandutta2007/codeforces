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

int N,M;
ll A[4040];
ll F[4040][4040];

vector<ll> dfs(int L,int R) {
	int C=L;
	int i,x,y;
	for(i=L;i<R;i++) if(A[i]<A[C]) C=i;
	vector<ll> X={0,(M-1)*A[C]};
	if(L<C) {
		vector<ll> Y=dfs(L,C);
		vector<ll> Z(X.size()+Y.size()-1,-1LL<<60);
		FOR(x,X.size()) FOR(y,Y.size()) {
			chmax(Z[x+y],X[x]+Y[y]-2*x*y*A[C]);
		}
		X=Z;
	}
	if(C+1<R) {
		vector<ll> Y=dfs(C+1,R);
		vector<ll> Z(X.size()+Y.size()-1,-1LL<<60);
		FOR(x,X.size()) FOR(y,Y.size()) {
			chmax(Z[x+y],X[x]+Y[y]-2*x*y*A[C]);
		}
		X=Z;
	}
	return X;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	
	auto V=dfs(0,N);
	cout<<V[M]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}