#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
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
int n,m,k;
string wrote[20];
string arc[500005];
int nxt[20][500005];
int dp[1<<15][300];
int func(){
	REP(i,n){
		nxt[i][k]=k;
		int last=k;
		for(int j=k-1;j>=0;--j){
			if(arc[j]==wrote[i]) last=j;
			nxt[i][j]=last;
		}
	}
	int maxi=n*(n-1);
	REP(i,1<<n) REP(j,maxi+1) dp[i][j]=INF;
	dp[0][0]=0;
	int tmp[20];
	REP(i,1<<n) REP(j,maxi+1) if(dp[i][j]<k){
		tmp[n]=0;
		for(int i2=n-1;i2>=0;--i2){
			tmp[i2]=tmp[i2+1]+(i>>i2&1);
		}
		REP(i2,n) if(!(i>>i2&1)){
			dp[i|(1<<i2)][j+tmp[i2]]=min(dp[i|(1<<i2)][j+tmp[i2]],nxt[i2][dp[i][j]]+1);
		}
	}
	int mininv=INF;
	REP(i,maxi+1) if(dp[(1<<n)-1][i]<=k){
		mininv=i;
		break;
	}
	return n*(n-1)/2-mininv+1;
}

int main(){
	scanf("%d",&n);
	REP(i,n) cin>>wrote[i];
	scanf("%d",&m);
	int res=-1,who;
	REP(i,m){
		scanf("%d",&k);
		REP(j,k) cin>>arc[j];
		int ans=func();
		if(res<ans){
			res=ans;
			who=i;
		}
	}
	if(res==-1) puts("Brand new problem!");
	else{
		printf("%d\n",who+1);
		printf("[:");
		REP(i,res) putchar('|');
		printf(":]\n");
	}
	return 0;
}