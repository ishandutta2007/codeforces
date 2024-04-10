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
int n;
int h[5005];
int sum[5005];
int dp[5005][5005];//dp[i][j]:=[i...j)
int mini[5005];
int main(){
	cin>>n;
	REP(i,n) cin>>h[i];
	sum[0]=0;
	REP(i,n) sum[i+1]=sum[i]+h[i];
	REP(i,5005) REP(j,5005) dp[i][j]=INF;
	dp[0][0]=0;
	REP(j,n){
		REP(i,n+2) mini[i]=INF;
		REP(i,j+1) if(dp[i][j]<INF){
			int back=sum[j]-sum[i];
			int lb=j,ub=n+1;
			while(ub-lb>1){
				int md=(lb+ub)>>1;
				if(sum[md]-sum[j]>=back) ub=md;
				else lb=md;
			}
			if(ub<=n) mini[ub]=min(mini[ub],dp[i][j]);
		}
		REP(i,n+1) mini[i+1]=min(mini[i+1],mini[i]);
		REPN(i,n+1,j+1){
			dp[j][i]=min(dp[j][i],mini[i]+(i-j-1));
		}
	}
	int res=INF;
	REP(i,n) res=min(res,dp[i][n]);
	printf("%d\n",res);

	return 0;
}