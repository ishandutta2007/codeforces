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

int T;
int K,N;
ll phi[101010];
ll PS[101010];
ll dp[103030][20];


ll add[303030];

ll sum(int L,int R) {
	ll ret=0;
	while(L<=R) {
		ll nex=min(R,R/(R/L));
		ret+=(nex-L+1)*PS[R/L];
		L=nex+1;
	}
	
	return ret;
}

void dfs(int step,int L,int R,int X,int Y) {
	if(L>R) return;
	int M=(L+R)/2;
	int tar=-1;
	int i;
	ll CS=sum(X+1,M);
	for(i=X;i<=min(M-1,Y);i++) {
		if(dp[i][step-1]+CS<dp[M][step]) {
			dp[M][step]=dp[i][step-1]+CS;
			tar=i;
		}
		CS-=PS[M/(i+1)];
	}
	
	dfs(step,L,M-1,X,tar);
	dfs(step,M+1,R,tar,Y);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=100000;i++) phi[i]=i;
	for(i=1;i<=100000;i++) {
		for(j=i*2;j<=100000;j+=i) phi[j]-=phi[i];
		PS[i]=PS[i-1]+phi[i];
	}
	for(i=1;i<=100000;i++) FOR(j,18) dp[i][j]=1LL<<60;
	for(i=1;i<=17;i++) dfs(i,1,100000,0,100000);
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		
		if(K>=18) {
			cout<<N<<endl;
		}
		else {
			cout<<dp[N][K]<<endl;
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}