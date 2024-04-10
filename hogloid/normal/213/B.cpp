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
int a[20];
lint dp[15][105];
int sum[20];
const lint mod=1000000007;
inline void add(lint& a,lint b){
	b%=mod;
	a+=b;
	a%=mod;
}
lint C[105][105];
int main(){
	REP(i,105){
		C[i][0]=1;
		for(int j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}

	scanf("%d",&n);
	REP(i,10) scanf("%d",&a[i]);
	REP(i,10) for(int j=i;j<10;++j) sum[i]+=a[j];
	lint res=0;
	for(int i=1;i<=n;++i){
		int rest=i;
		REP(j,10) rest-=a[j];
		if(rest<0) continue;
		memset(dp,0,sizeof(dp));
		dp[0][rest]=1;
		REP(j,10) REP(k,rest+1) if(dp[j][k]>0){
			REP(k2,k+1){
				if(j!=0) add(dp[j+1][k-k2],dp[j][k]*C[sum[j]+k][k2+a[j]]);
				else if(sum[j]+k-1>=0) add(dp[j+1][k-k2],dp[j][k]*C[sum[j]+k-1][k2+a[j]]);
			}
		}
		add(res,dp[10][0]);
	}
	cout<<res<<endl;
	return 0;
}