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


int N,K,L;
int D[151515];
int A[151515];

ll dp[555][555];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>K;
	FOR(i,N) cin>>D[i];
	D[N]=L;
	FOR(i,N) cin>>A[i];
	FOR(x,N+2) FOR(y,N+2) dp[x][y]=1LL<<60;
	dp[0][K]=0;
	
	FOR(x,N) {
		FOR(y,N) if(dp[x][y]<1LL<<60) {
			for(k=x+1;k-x<=y+1&&k<=N;k++) {
				dp[k][y-(k-x-1)]=min(dp[k][y-(k-x-1)],dp[x][y]+1LL*(D[k]-D[x])*A[x]);
			}
		}
	}
	ll ret=1LL<<60;
	FOR(i,N) ret=min(ret,dp[N][i]);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}