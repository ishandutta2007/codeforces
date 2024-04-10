#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,k;
lint m;
lint C[105][105];
const lint mod=1000000007;
int dp[105][10005];
int memo[105][2];
lint mpow(lint a,lint k){
	lint res=1;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}
int main(){
	REP(i,105){
		C[i][0]=1;
		REPN(j,i+1,1) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	cin>>n>>m>>k;
	dp[0][0]=1;
	lint tmp=(m+n-1)/n;
	REP(i,105) memo[i][0]=mpow(C[n][i],tmp),memo[i][1]=mpow(C[n][i],tmp-1);
	REP(i,n) REP(j,k+1) if(dp[i][j]>0){
		if(j+(n-i)*n<k) continue;
		lint mul;
		int lim=min(n,k-j);
		int flag=((m-i+n-1)/n==tmp?1:0);
		REP(l,lim+1){
			if(flag) dp[i+1][j+l]+=(dp[i][j]*(lint)memo[l][0])%mod;
			else dp[i+1][j+l]+=(dp[i][j]*(lint)memo[l][1])%mod;
			if(dp[i+1][j+l]>=mod) dp[i+1][j+l]-=mod;
		}
	}
	cout<<dp[n][k]<<endl;
	return 0;
}