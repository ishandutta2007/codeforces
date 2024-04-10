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
char s[15];
pair<pi,int> es[1000005];

int dp[30];
int main(){
	scanf("%d",&n);
	REP(i,n){
		scanf("%s",s);
		int len=strlen(s);
		es[i]=mp(mp(s[0]-'a',s[len-1]-'a'),len);
	}
	
	int res=0;
	REP(i,26){
		memset(dp,-1,sizeof(dp));
		dp[i]=0;
		REP(j,n) if(dp[es[j].fr.fr]>=0){
			dp[es[j].fr.sc]=max(dp[es[j].fr.sc],dp[es[j].fr.fr]+es[j].sc);
		}
		res=max(res,dp[i]);
	}
	cout<<res<<endl;
	return 0;
}