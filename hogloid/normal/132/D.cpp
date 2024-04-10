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
int dp[2][1000005],sel[2][1000005],back[2][1000005];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	REP(i,2) REP(j,1000005) dp[i][j]=INF;
	reverse(s,s+n);
	s[n++]='0';
	dp[0][0]=0;
	REP(i,n){
		if(dp[0][i]<INF){
			if(s[i]=='0' && dp[0][i+1]>dp[0][i]){
				dp[0][i+1]=dp[0][i];
				sel[0][i+1]=0;
				back[0][i+1]=0;
			}
			if(s[i]=='1'){
				if(dp[0][i+1]>dp[0][i]+1){
					dp[0][i+1]=dp[0][i]+1;
					sel[0][i+1]=1;
					back[0][i+1]=0;
				}
				if(dp[1][i+1]>dp[0][i]+1){
					dp[1][i+1]=dp[0][i]+1;
					sel[1][i+1]=-1;
					back[1][i+1]=0;
				}
			}
		}
		if(dp[1][i]<INF){
			if(s[i]=='1' && dp[1][i+1]>dp[1][i]){
				dp[1][i+1]=dp[1][i];
				sel[1][i+1]=0;
				back[1][i+1]=1;
			}
			if(s[i]=='0'){
				if(dp[0][i+1]>dp[1][i]+1){
					dp[0][i+1]=dp[1][i]+1;
					sel[0][i+1]=1;
					back[0][i+1]=1;
				}
				if(dp[1][i+1]>dp[1][i]+1){
					dp[1][i+1]=dp[1][i]+1;
					sel[1][i+1]=-1;
					back[1][i+1]=1;
				}
			}
		}
	}
	int res=dp[0][n],cur=0;

	printf("%d\n",res);
	for(int i=n;i>0;--i){
		if(sel[cur][i]){
			if(sel[cur][i]>0) putchar('+');
			else putchar('-');
			printf("%d^%d\n",2,i-1);
		}
		cur=back[cur][i];
	}

	
	return 0;
}