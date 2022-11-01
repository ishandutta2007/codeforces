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
int buf[305][305];
int n;
int dp[305][305][305];
int main(){
	scanf("%d",&n);
	REP(i,n) REP(j,n) scanf("%d",&buf[i][j]);
	REP(i,n) REP(j,n) REP(k,n) dp[i][j][k]=-INF;
	dp[0][0][0]=buf[0][0];
	REP(i,n){
		REP(j,n-1) REP(k,n) if(dp[i][j][k]>-INF){	
			if(j<k-1) dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]+buf[j+1][i]);
			else dp[i][j+1][k]=max(dp[i][j+1][k],dp[i][j][k]);
		}
		REP(j,n) REP(k,n-1) if(dp[i][j][k]>-INF){
			dp[i][j][k+1]=max(dp[i][j][k+1],dp[i][j][k]+buf[k+1][i]);
		}
		if(i<n-1) REP(j,n) REPN(k,n,j) if(dp[i][j][k]>-INF){
			dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+(j==k?buf[j][i+1]:buf[j][i+1]+buf[k][i+1]));
		}
	}
	printf("%d\n",dp[n-1][n-1][n-1]);
	return 0;
}