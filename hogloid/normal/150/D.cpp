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
char s[200];
int dp[200][200][205];
bool isPalin[200][200];
int worth[200];
int n;

int rec(int l,int r,int d){
	if(r<=l){
		if(d>0){
			if(worth[d-1]<0) return -INF;
			return worth[d-1];
		}
		return 0;
	}
	int& res=dp[l][r][d];
	if(res!=-1) return res;
	res=-INF;

	if(d>0 && worth[d-1]!=-1){
		res=max(res,worth[d-1]+rec(l,r,0));
	}
	if(worth[d]!=-1){
		res=max(res,worth[d]+rec(l+1,r,0));
	}

	REPN(i,r,l+1) if(s[i]==s[l]){
		res=max(res,rec(l+1,i,d+2)+rec(i+1,r,0));
	}

	REPN(i,r,l+1){
		res=max(res,rec(l,i,0)+rec(i,r,d));
	}

	if(res<0) res=-INF;

	return res;
}
	

int main(){
	cin>>n;
	REP(i,n) cin>>worth[i];
	scanf("%s",s);

	memset(dp,-1,sizeof(dp));

	int dp2[200]={0};
	for(int i=1;i<=n;++i){
		dp2[i]=dp2[i-1];

		REP(j,i){
			dp2[i]=max(dp2[i],dp2[j]+rec(j,i,0));
		}
	}
	printf("%d\n",dp2[n]);
	return 0;
}