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


int N,K;
string S;

int dp[1<<17];
int nex[202020][17];
int can[202020][17];

int hoge(int len) {
	if(len*K>N) return 0;
	int i,j;
	FOR(i,K) can[N][i]=N+1;
	for(i=N-1;i>=0;i--) {
		FOR(j,K) can[i][j]=can[i+1][j];
		int ok=(1<<K)-1;
		FOR(j,K) {
			if(nex[i][j]<i+len) ok&=(1<<j);
		}
		FOR(j,K) if(ok&(1<<j)) can[i][j]=i+len;
	}
	int mask;
	FOR(mask,1<<K) dp[mask]=N+1;
	dp[0]=0;
	FOR(mask,1<<K) if(dp[mask]<N) {
		FOR(j,K) if((mask&(1<<j))==0) dp[mask|(1<<j)]=min(dp[mask|(1<<j)],can[dp[mask]][j]);
		
	}
	return dp[(1<<K)-1]<=N;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	
	FOR(i,K) nex[N][i]=N;
	for(i=N-1;i>=0;i--) {
		FOR(j,K) nex[i][j]=nex[i+1][j];
		nex[i][S[i]-'a']=i;
	}
	
	int ma=0;
	for(i=20;i>=0;i--) if(hoge(ma+(1<<i))) ma+=1<<i;
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}