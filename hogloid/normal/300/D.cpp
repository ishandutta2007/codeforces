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

lint dp[5][40][1005];
int solve(int n,int k){
	int div=0;
	while(n>=3){
		if(n&1){
			n/=2;
			++div;
		}else break;
	}
	return dp[4][div][k];
}
const int mod=7340033;
int main(){
	int cnt=0;
	dp[4][0][0]=1;
	REPN(i,40,1){
		REP(j,1002) REP(t,5){
			if(t==0){
				if(j==0) dp[0][i][j]=1;
				else dp[0][i][j]=0;
			}else if(t==4){
				if(j==0) dp[t][i][j]=1;
				else{
					REP(k,j){
						dp[t][i][j]=(dp[t][i][j]
							+dp[t-1][i][j-1-k]*dp[4][i-1][k]%mod)%mod;
					}
				}
			}else{
				REP(k,j+1){
					dp[t][i][j]=(dp[t][i][j]
						+dp[t-1][i][j-k]*dp[4][i-1][k]%mod)%mod;
				}
			}
		}
	}


	int q;
	scanf("%d",&q);
	REP(hoge,q){
		int n,k;scanf("%d%d",&n,&k);
		printf("%d\n",solve(n,k));
	}



	return 0;
}