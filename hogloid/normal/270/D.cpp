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
int n,m;
int seq[100005];
int dp[5005][5005];
int main(){
	scanf("%d%d",&n,&m);
	REP(i,n){
		scanf("%d%*f",&seq[i]);
		--seq[i];
	}
	REP(i,5005) REP(j,5005) dp[i][j]=INF;
	dp[0][0]=0;
	REP(i,n) REP(j,m) if(dp[i][j]<INF){
		dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
		if(seq[i]==j) dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
		else dp[i+1][j]=min(dp[i+1][j],dp[i][j]+1);
	}
	int res=INF;
	REP(j,m) res=min(res,dp[n][j]);

	printf("%d\n",res);


	return 0;
}