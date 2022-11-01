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
static const lint BIG=2.5e18;
int n,m;
lint k;
int buf[105][105];
int pri[205];
int len;
int seq[205],tmp[205],sum[205];

lint dp[205][205];
void add(lint &a,lint b){
	a=a+b;
	if(a>=BIG) a=BIG;
}
lint check(){
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	REP(i,len) REP(j,i+1) if(dp[i][j]>0){
		if(j>0 && (seq[i]==0 || seq[i]==-1)) add(dp[i+1][j-1],dp[i][j]);
		if(seq[i]==1 || seq[i]==-1) add(dp[i+1][j+1],dp[i][j]);
	}
	return dp[len][0];
}

int main(){
	REP(i,205) pri[i]=INF;
	cin>>n>>m>>k;
	--k;
	REP(i,n) REP(j,m){
		int a;cin>>a;
		pri[i+j]=min(pri[i+j],a);
	}
	
	memset(seq,-1,sizeof(seq));
	len=n+m-1;
	REP(hoge,len){
		int mini=INF,who;
		REP(i,len) if(seq[i]==-1 && pri[i]<mini){
			mini=pri[i];
			who=i;
		}
		seq[who]=1;
		lint val=check();
		if(val<=k){
			seq[who]=0;
			k-=val;
		}
	}
	char conv[5];
	conv[0]=')';conv[1]='(';
	REP(i,n){
		REP(j,m) putchar(conv[seq[i+j]]);
		putchar('\n');
	}

	return 0;
}