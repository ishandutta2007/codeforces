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
int perm[1005];

double dp[1005][1005];//prob. of perm[i]>perm[j]
int main(){
	cin>>n>>m;
	REP(i,n){
		cin>>perm[i];--perm[i];
	}

	REP(i,n) REP(j,n){
		if(perm[i]>perm[j]) dp[i][j]=1;
		else dp[i][j]=0;
	}

	REP(i,m){
		int a,b;cin>>a>>b;--a;--b;

		REP(j,n) if(j!=a && j!=b){
			dp[j][a]=(dp[j][a]+dp[j][b])/2;
			dp[a][j]=1-dp[j][a];

			dp[j][b]=dp[j][a];
			dp[b][j]=dp[a][j];
		}
		dp[a][b]=dp[b][a]=0.5;
	}
	
	double res=0;

	REP(i,n) REP(j,i) res+=dp[j][i];

	printf("%.10f\n",res);


	return 0;
}