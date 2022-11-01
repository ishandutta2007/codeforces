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
int dp[2][33][33][33][33];
int n,h;
const int mod=1000000009;
inline void chadd(int& a,int b){
	a+=b;
	if(a>=mod) a-=mod;
}
int cur,nxt;
inline void doit(int a,int b,int c,int d,int v){
	if(a<b) swap(a,b);
	if(b<c) swap(b,c);
	if(c<d) swap(c,d);
	chadd(dp[nxt][a][b][c][d],v);
}
int main(){
	scanf("%d%d",&n,&h);
	cur=0;nxt=1;
	dp[cur][1][1][1][1]=1;
	
	REP(i,n){
		REP(j,h+2) REP(j2,j+1) REP(j3,j2+1) REP(j4,j3+1) if(dp[cur][j][j2][j3][j4]>0){
			int k=min(h+1,j+1),k2=min(h+1,j2+1),k3=min(h+1,j3+1),k4=min(h+1,j4+1),
					v=dp[cur][j][j2][j3][j4];
			
			doit(j==h+1?h+1:1,k2,k3,k4,v);
			doit(k,j2==h+1?h+1:1,k3,k4,v);
			doit(k,k2,j3==h+1?h+1:1,k4,v);
			doit(k,k2,k3,j4==h+1?h+1:1,v);
		}

		memset(dp[cur],0,sizeof(dp[cur]));
		swap(cur,nxt);
	}
	int res=0;
	REP(j,h+2) REP(j2,h+2) REP(j3,h+2) REP(j4,h+2){
		if(j<=h || j2<=h || j3<=h || j4<=h){
			chadd(res,dp[cur][j][j2][j3][j4]);
		}
	}
	printf("%d\n",res);

	return 0;
}