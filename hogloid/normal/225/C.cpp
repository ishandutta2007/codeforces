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
int h,w,x,y;
char buf[1005][1005];
int black[1005];
int dp[2][1005];
int sum[1005];
int main(){
	cin>>h>>w>>x>>y;
	REP(i,h) scanf("%s",buf[i]);
	REP(i,h) REP(j,w) if(buf[i][j]=='#') ++black[j];
	REP(i,w) sum[i+1]=sum[i]+black[i];

	REP(i,2) REP(j,1005) dp[i][j]=INF;
	dp[0][0]=dp[1][0]=0;
	REP(i,w){
		if(dp[0][i]<INF){//color black
			REPN(j,min(w+1,i+y+1),i+x){
				dp[1][j]=min(dp[1][j],dp[0][i]+ (j-i)*h-(sum[j]-sum[i]));
			}
		}
		if(dp[1][i]<INF){
			REPN(j,min(w+1,i+y+1),i+x){
				dp[0][j]=min(dp[0][j],dp[1][i]+ sum[j]-sum[i]);
			}
		}
	}
	printf("%d\n",min(dp[1][w],dp[0][w]));

	return 0;
}