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
int n,m,r;
int g[65][65][65],mini[65][65];

int dp[65][65][65];
int main(){
	scanf("%d%d%d",&n,&m,&r);
	REP(i,m) REP(j,n) REP(k,n) scanf("%d",&g[i][j][k]);
	REP(i,m) REP(j,n) REP(k,n) REP(l,n) g[i][k][l]=min(g[i][k][l],g[i][k][j]+g[i][j][l]);

	REP(i,65) REP(j,65) mini[i][j]=INF;
	REP(i,m) REP(j,n) REP(k,n) mini[j][k]=min(mini[j][k],g[i][j][k]);
	REP(i,65) REP(j,65) REP(k,65) dp[i][j][k]=INF;
	REP(i,n){
		dp[i][0][i]=0;
		REP(j,64) REP(k,n) if(dp[i][j][k]<INF){
			REP(l,n) dp[i][j+1][l]=min(dp[i][j+1][l],dp[i][j][k]+mini[k][l]);
		}
	}
	REP(hoge,r){
		int a,b,k;scanf("%d%d%d",&a,&b,&k);--a;--b;
		k=min(62,k);
		printf("%d\n",dp[a][k+1][b]);
	}


	return 0;
}