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
int ar[100005];
char s[100005];

int dp[2][100005];
int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	scanf("%s",s);
	reverse(ar,ar+n);
	reverse(s,s+n);

	memset(dp,-1,sizeof(dp));

	dp[1][0]=0;//dp[0]:lower dp[1] equal

	REP(i,n){
		if(dp[0][i]!=-1){
			dp[0][i+1]=max(dp[0][i+1],ar[i]+dp[0][i]);
		}
		if(dp[1][i]!=-1){
			if(s[i]=='1'){
				dp[0][i+1]=max(dp[0][i+1],dp[1][i]);
				dp[1][i+1]=max(dp[1][i+1],dp[1][i]+ar[i]);
			}else{
				dp[1][i+1]=max(dp[1][i+1],dp[1][i]);
			}
		}
	}
	cout<<max(dp[1][n],dp[0][n])<<endl;



	return 0;
}