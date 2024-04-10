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
lint dp[2][2005][2005];
lint imos[2][2005];

lint sum[2005][2005];//[hei][wid]
const lint mod=1000000007;
void chadd(lint& a,lint b){
	a+=b;
	if(a>=mod) a-=mod;
}
int main(){
	scanf("%d%d",&n,&m);

	REPN(i,m+1,2){
		dp[0][1][i]=1;
	}
	lint res=0;

	REPN(i,n+1,1){
		memset(imos,0,sizeof(imos));

		REPN(j,m+1,2){
			if(dp[0][i][j]>0){
				chadd(imos[0][j],dp[0][i][j]);
			}
		}

		REP(j,m+1) chadd(imos[0][j+1],imos[0][j]);
		REP(j,m+1) chadd(imos[0][j+1],imos[0][j]);

		REPN(j,m+1,2){
			dp[0][i+1][j]=imos[0][j];
		}
	}


	REPN(i,n+1,1) REPN(j,m+1,2) if(dp[0][i][j]>0){
		int rest=n+1-i;
		chadd(sum[rest][j],(dp[0][i][j]-dp[0][i-1][j]+mod)%mod*(m+1-j)%mod);
	}

	for(int i=n;i>0;--i) REPN(j,m+1,2) chadd(sum[i-1][j],sum[i][j]);
	for(int i=n;i>0;--i) REPN(j,m+1,2) chadd(sum[i-1][j],sum[i][j]);
	
	REP(i,n+1) REPN(j,m+1,2) if(dp[0][i][j]>0){
		chadd(res,dp[0][i][j]*sum[i][j]%mod);
	}

	cout<<res<<endl;
	return 0;
}