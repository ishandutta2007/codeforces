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
int k,n,t2;
int b[100005];
int zip[100005];

int dp[100005],itr[100005];
void solve(){
	REP(i,n) scanf("%d",&b[i]),zip[i]=b[i];
	sort(zip,zip+n);
	int zn=unique(zip,zip+n)-zip;
	REP(i,n) b[i]=lower_bound(zip,zip+zn,b[i])-zip;

	int T=min(t2,zn+2);
	REP(i,zn) dp[i]=INF;
	memset(itr,0,sizeof(itr));

	REP(i,T) REP(j,n){
		while(dp[itr[b[j]]]<b[j]) ++itr[b[j]];
		dp[itr[b[j]]]=b[j];
	}

	int res=0;
	REP(i,zn) if(dp[i]<INF) res=i+1;

	printf("%d\n",res);
}

int main(){
	scanf("%d%d%*d%d",&k,&n,&t2);
	
	REP(hoge,k){
		solve();
	}

	return 0;
}