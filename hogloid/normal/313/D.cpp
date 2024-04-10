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
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m,k;
static const lint INF =1e18; 

lint dp[305][305];
lint work[305][305];
int main(){
	cin>>n>>m>>k;
	REP(i,n+1) REP(j,n+1) work[i][j]=INF;

	REP(i,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;
		work[a][b]=min(work[a][b],(lint)c);
	}
	REPN(i,n,1) REP(j,n+1) work[i][j]=min(work[i][j],work[i-1][j]);



	REP(i,n+1) REP(j,n+1) dp[i][j]=INF;
	
	lint res=INF;
	dp[0][0]=0;
	REP(i,n+1) REP(j,n+1) if(dp[i][j]<INF){
		if(j>=k) res=min(res,dp[i][j]);
		REPN(dst,n+1,i+1) if(work[i][dst]<INF){
			dp[dst][j+dst-i]=min(dp[dst][j+dst-i],dp[i][j]+work[i][dst]);
		}
		dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
	}

	if(res==INF) res=-1;

	cout<<res<<endl;




	return 0;
}