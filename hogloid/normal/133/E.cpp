#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
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
char s[110];
int n;
bool dp[105][205][55][2];
int main(){
	scanf("%s%d",s,&n);
	int len=strlen(s);
	dp[0][100][0][0]=true;
	int sign[2]={1,-1};
	REP(i,len) REP(j,205) REP(k,n+1) REP(l,2) if(dp[i][j][k][l]){
		dp[i][j][k+2][l]=true;
		dp[i+1][j+sign[l]][k+(s[i]=='F'?0:1)][l]=true;
		dp[i+1][j][k+(s[i]=='T'?0:1)][l^1]=true;
	}
	int res=-1;
	REP(i,205) REP(k,n+1) REP(l,2) if(k==n && dp[len][i][k][l]) res=max(res,abs(i-100));
	printf("%d\n",res);

	return 0;
}