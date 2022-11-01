#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
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
typedef pair<lint,lint> pi;

int n,k;
lint ar[30];
lint bad[5];
const lint mod=1000000007;

lint dp[1<<24],sum[1<<24];
int main(){
	cin>>n;
	REP(i,n) cin>>ar[i];
	cin>>k;
	REP(i,k) cin>>bad[i];
	
	sort(bad,bad+k);
	k=unique(bad,bad+k)-bad;
	bad[k]=bad[k+1]=-1;
	
	int m=(1<<n);	
	REP(i,m){
		int last=__builtin_ctz(i);
		sum[i]=sum[i^(1<<last)]+ar[last];
		if(sum[i]==bad[0] || sum[i]==bad[1]) dp[i]=-1;
	}
	REP(i,m){
		if(dp[i]==-1) dp[i]=0;
		else{
			REP(j,n) if(i>>j&1) dp[i]+=dp[i^(1<<j)];
			dp[i]%=mod;
			if(i==0) dp[i]=1;
		}
	}
	cout<<dp[m-1]<<endl;

	return 0;
}