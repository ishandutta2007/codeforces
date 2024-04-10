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

char s[100005];
int k;
int forb[30][30];

int dp[100005][30];
int main(){
	scanf("%s",s);
	scanf("%d",&k);
	REP(i,k){
		char tmp[10];scanf("%s",tmp);
		forb[tmp[0]-'a'][tmp[1]-'a']=forb[tmp[1]-'a'][tmp[0]-'a']=1;
	}
	int n=strlen(s);

	REP(i,n+1) REP(j,27) dp[i][j]=INF;
	dp[0][26]=0;
	REP(i,n) REP(c,27) if(dp[i][c]<INF){
		dp[i+1][c]=min(dp[i+1][c],dp[i][c]+1);
		if(!forb[s[i]-'a'][c]) dp[i+1][s[i]-'a']=min(dp[i+1][s[i]-'a'],dp[i][c]);
	}
	int res=INF;
	REP(i,27) res=min(res,dp[n][i]);

	printf("%d\n",res);

	return 0;
}