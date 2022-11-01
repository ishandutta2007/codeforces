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
double dp[100005][105];
double tmp[105];
int init[100005],has[100005];
double C[1000005][10];
int main(){
	REP(i,105) REP(j,105) dp[i][j]=0;
	REP(i,1000005){
		C[i][0]=1;
		REP(j,min(i,9)) C[i][j+1]=C[i-1][j]+C[i-1][j+1];
	}
	scanf("%d",&n);
	double cur=0;
	REP(i,n){
		scanf("%d",&init[i]);
		has[i]=init[i];
		dp[i][init[i]]=1;
		if(init[i]==0) ++cur;
	}
	int q;scanf("%d",&q);
	while(q--){
		int u,v,k;scanf("%d%d%d",&u,&v,&k);--u;--v;

		cur-=dp[u][0];
		for(int j=0;j<105;++j) tmp[j]=0;
		for(int i=0;i<=init[u];++i) if(dp[u][i]>1e-30){
			for(int j=0;j<=k && j<=i;++j){
				tmp[i-j]+=dp[u][i]*C[i][j]*C[has[u]-i][k-j]/C[has[u]][k];
			}
		}
		for(int j=0;j<105;++j) dp[u][j]=tmp[j];
		has[u]-=k;
		has[v]+=k;
		cur+=dp[u][0];
		printf("%.10f\n",cur);
	}


	return 0;
}