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
int n,q,t;
int a[305];
int grat[305],back[305];
int done[305];

int val[305];

int dp[305][100005];

const int mod=1000000007;
void chadd(int& a,int b){
	a=(a+b);
	if(a>=mod) a-=mod;
}
int main(){
	memset(back,-1,sizeof(back));
	memset(grat,-1,sizeof(grat));
	scanf("%d%d%d",&n,&q,&t);
	REP(i,n) scanf("%d",&a[i]);


	REP(i,q){
		int b,c;scanf("%d%d",&b,&c);--b;--c;
		grat[c]=b;
		back[b]=c;
	}
	int m=0;
	lint nega=0;
	REP(i,n) if(back[i]==-1){
		vector<int> ve;
		int cur=i;
		while(cur!=-1){
			done[cur]=1;
			ve.pb(cur);
			cur=grat[cur];
		}
		int furth=0,later=0;
		for(int j=ve.size()-1;j>=0;--j){
			nega+=later;
			later+=a[ve[j]];
			val[ve[j]]=later;
		}
	}
	REP(i,n) if(!done[i]){
		puts("0");
		return 0;
	}
	if(t-nega<0){
		puts("0");
		return 0;
	}
	t-=nega;
	
	memset(dp,0,sizeof(dp));
	
	dp[0][0]=1;
	
	REP(i,n) REP(j,t+1) if(dp[i][j]>0){
		if(j+val[i]<=t) chadd(dp[i][j+val[i]],dp[i][j]);
		chadd(dp[i+1][j],dp[i][j]);
	}
	printf("%d\n",dp[n][t]);
	
	return 0;
}