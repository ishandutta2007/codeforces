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
char s[1000005];

inline void chmin(int& a,int b){
	a=min(a,b);
}

int dp[1000005][3];//dp[index][add]
int main(){
	scanf("%s",s);
	int n=strlen(s);
	reverse(s,s+n);
	s[n]='0';
	++n;
	reverse(s,s+n);


		
	REP(j,1000005) REP(t,3) dp[j][t]=INF;
	dp[0][1]=0;

	REP(i,n){
		chmin(dp[i+1][1],dp[i][1]+(s[i]=='1'));
		chmin(dp[i+1][2],dp[i][1]+(s[i]=='0')+1);
		chmin(dp[i+1][0],dp[i][1]+(s[i]=='1')+2);

		chmin(dp[i+1][2],dp[i][2]+(s[i]=='0'));
		chmin(dp[i+1][1],dp[i][2]+(s[i]=='1')+1);
		chmin(dp[i+1][0],dp[i][2]+(s[i]=='1')+3);

		chmin(dp[i+1][2],dp[i][0]+(s[i]=='0')+2);
		chmin(dp[i+1][1],dp[i][0]+(s[i]=='0'));
		chmin(dp[i+1][0],dp[i][0]+(s[i]=='1')+2);
	}

	int res=min(dp[n][1],min(dp[n][0],dp[n][2])+1);


	printf("%d\n",res);

	return 0;
}