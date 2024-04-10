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
typedef long double ld;
int n,m;
int k[1005];
int c[1005][1005];
int all[1005];
int large[1005],same[1005],other[1005];
ld prob[1005][1005];
ld C[1005][1005];
ld dp[1005][1005],way[1005][1005];
int main(){
	REP(i,1005){
		C[i][0]=1.0;
		REPN(j,i+1,1) C[i][j]=C[i-1][j]+C[i-1][j-1];
	}

	int cnt=0;
	cin>>n>>m;
	REP(i,m){
		scanf("%d",&k[i]);
		REP(j,k[i]) scanf("%d",&c[i][j]),all[cnt++]=c[i][j];
		sort(c[i],c[i]+k[i],greater<int>());
	}
	sort(all,all+cnt,greater<int>());

	int border=all[n-1];
	REP(i,m) REP(j,k[i]){
		if(c[i][j]>border) ++large[i];
		else if(c[i][j]==border) ++same[i];
		else ++other[i];
	}
	REP(i,m){
		for(int j=large[i];j<=large[i]+same[i];++j){
			prob[i][j]=C[same[i]][j-large[i]]/C[k[i]][j];
		}
	}
	REP(i,1005) REP(j,1005) dp[i][j]=way[i][j]=0;
	dp[0][0]=1;
	way[0][0]=1;
	
	REP(i,m) REP(j,n+1){
		if(dp[i][j]>1e-11){
			for(int j2=large[i];j2<=large[i]+same[i] && j+j2<=n;++j2){
				dp[i+1][j+j2]+=dp[i][j]*prob[i][j2];
			}
		}
		if(way[i][j]>1e-11){
			for(int j2=large[i];j2<=large[i]+same[i] && j+j2<=n;++j2){
				way[i+1][j+j2]+=way[i][j];
			}
		}
	}
	printf("%.11lf\n",(double)(dp[m][n]/way[m][n]));
	return 0;
}