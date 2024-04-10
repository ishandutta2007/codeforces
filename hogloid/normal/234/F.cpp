#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<fstream>
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
int cola,colb;
int h[205];
int dp[2][205][40005];
int sum[205];
int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	cin>>n;
	cin>>cola>>colb;
	REP(i,n) cin>>h[i];
	h[n]=0;

	REP(i,205) REP(j,40005)  dp[0][i][j]=dp[1][i][j]=INF;
	sum[0]=0;
	REP(i,n) sum[i+1]=sum[i]+h[i];
	dp[0][0][cola]=dp[1][0][cola]=0;
	REP(i,n) REP(j,40005){
		int spent=cola-j;
		int other=sum[i]-spent;
		if(other>colb) continue;
		int cost=(i==0?0:min(h[i-1],h[i]));
		if(dp[0][i][j]<INF){
			if(j>=h[i]) dp[0][i+1][j-h[i]]=min(dp[0][i+1][j-h[i]],dp[0][i][j]);
			dp[1][i+1][j]=min(dp[1][i+1][j],dp[0][i][j]+cost);
		}

		if(dp[1][i][j]<INF){
			if(j>=h[i]) dp[0][i+1][j-h[i]]=min(dp[0][i+1][j-h[i]],dp[1][i][j]+cost);
			dp[1][i+1][j]=min(dp[1][i+1][j],dp[1][i][j]);
		}
	}
	int res=INF;
	REP(j,40005){
		int spent=cola-j;
		int other=sum[n]-spent;
		if(other>colb) continue;
		res=min(res,min(dp[0][n][j],dp[1][n][j]));
	}
	if(res==INF) res=-1;
	cout<<res<<endl;




	return 0;
}