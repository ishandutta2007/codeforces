#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define REP(i,m) for(int i=0;i<(int)m;++i)
#define REPN(i,m,in) for(int i=in;i<(int)m;++i)
#define pb push_back
#define mp make_pair
#define EPS (1e-8)
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
typedef long double ld;
int dp[4005][4005];
pi task[4005];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	task[0]=mp(0,0);
	++n;
	REPN(i,n,1){
		scanf("%d%d",&task[i].fr,&task[i].sc);
		--task[i].fr;
	}
	REP(i,n) REP(j,k+1) dp[i][j]=INF;
	dp[0][0]=0;
	int res=0;
	REP(i,n) REP(j,k+1) if(dp[i][j]<INF){
		dp[i+1][j]=min(dp[i+1][j],task[i+1].sc+max(0,dp[i][j]-(task[i+1].fr-task[i].fr)));
		dp[i+1][j+1]=min(dp[i+1][j+1],max(0,dp[i][j]-(task[i+1].fr-task[i].fr)));
		int rest=k-j;
		if(i+rest+1>=n) res=max(86400-task[i].fr-dp[i][j],res);
		else res=max(res,task[i+rest+1].fr-task[i].fr-dp[i][j]);
	}
	printf("%d\n",res);


	return 0;
}