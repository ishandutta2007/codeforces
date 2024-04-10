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
int h,w;

int dp[205][205][205][2][2],tmp[205][205][2][2];
const lint mod=1000000007;
inline void chadd(int & a,int b){
	a+=b;
	if(a<0) a+=mod;
	if(a>=mod) a-=mod;
}
int sum[205][205][2][2];
void add(int l,int b,int r,int t,int f,int f2,int c){
	if(c==0) return;
	if(l>=r || b>=t) return;
	chadd(sum[l][b][f][f2],c);
	chadd(sum[r][t][f][f2],c);
	chadd(sum[l][t][f][f2],-c);
	chadd(sum[r][b][f][f2],-c);
}

int main(){
	scanf("%d%d",&h,&w);
	

	int res=0;


	REP(i,h){
		memset(sum,0,sizeof(sum));
		memset(tmp,0,sizeof(tmp));
		REP(j,w) REPN(k,w,j) chadd(dp[i][j][k][0][0],1);
		REP(j,w) for(int k=w-1;k>=j;--k){
			REP(t,2) REP(t2,2) if(dp[i][j][k][t][t2]){
				chadd(res,dp[i][j][k][t][t2]);
			}

			chadd(tmp[j][k-1][0][1],dp[i][j][k][0][0]);
			chadd(tmp[j+1][k][1][0],dp[i][j][k][0][0]);
			chadd(tmp[j+1][k-1][1][1],dp[i][j][k][0][0]);
			chadd(tmp[j+1][k][1][1],dp[i][j][k][0][1]);
			chadd(tmp[j][k-1][1][1],dp[i][j][k][1][0]);

			REP(t,2) REP(t2,2) chadd(dp[i][j][k][t][t2],tmp[j][k][t][t2]);

			add(0,k,j+1,w,0,0,dp[i][j][k][0][0]);
			add(j,k,k+1,w,1,0,dp[i][j][k][1][0]);
			add(0,j,j+1,k+1,0,1,dp[i][j][k][0][1]);
			add(j,0,w,k+1,1,1,dp[i][j][k][1][1]);
		}
		REP(t,2) REP(t2,2){
			REP(j,w) REP(k,w) chadd(sum[j][k+1][t][t2],sum[j][k][t][t2]);
			REP(j,w) REP(k,w) chadd(sum[j+1][k][t][t2],sum[j][k][t][t2]);
		}

		REP(j,w) REP(k,w) REP(t,2) REP(t2,2) dp[i+1][j][k][t][t2]=sum[j][k][t][t2];
	}

	cout<<res<<endl;


	return 0;
}