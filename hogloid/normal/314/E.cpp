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
char s[100005];

unsigned int dp[2][100005];
int main(){
	scanf("%d%s",&n,s);
	int cur=0,nxt=1;
	dp[cur][0]=1;
	REP(i,n){
		int lim=min(n,min(i+2,n-i+2));
		if(s[i]!='?'){
			dp[nxt][0]=0;
			REPN(j,lim,1) dp[nxt][j]=dp[cur][j-1];
		}else{
			dp[nxt][0]=dp[cur][1];
			REPN(j,lim,1) dp[nxt][j]=dp[cur][j-1]*25+dp[cur][j+1];
		}
		swap(cur,nxt);
	}
	unsigned int res=dp[cur][0];
	cout<<res<<endl;
	

	return 0;
}