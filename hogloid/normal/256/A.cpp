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
int n;
int b[4005];
int next[4005];
int dp[4005][4005];
int main(){
	cin>>n;
	REP(i,n) cin>>b[i];
	int res=1;
	REP(i,n){
		next[i]=-1;
		int cnt=1;
		REPN(j,n,i+1) if(b[i]==b[j]){
			if(next[i]==-1) next[i]=j;
			++cnt;
		}
		res=max(res,cnt);
	}

	for(int i=n-1;i>=0;--i) REPN(j,n,i+1) if(b[i]!=b[j]){
		dp[i][j]=2;
		if(next[i]!=-1){
			if(j<next[i]) dp[i][j]=max(2,dp[j][next[i]]+1);
			else dp[i][j]=max(2,dp[next[i]][j]);
		}
		res=max(res,dp[i][j]);
	}
	cout<<res<<endl;


	return 0;
}