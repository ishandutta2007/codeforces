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
lint fib[150];
lint dp[100][2];
int ind[150];
int main(){
	fib[0]=1;fib[1]=1;
	for(int i=2;i<90;++i) fib[i]=fib[i-1]+fib[i-2];
	int t;scanf("%d",&t);
	while(t--){
		lint n;scanf("%I64d",&n);
		
		int m=0;
		for(int i=89;i>=1;--i) if(fib[i]<=n){
			n-=fib[i];
			ind[m++]=i;
		}
		reverse(ind,ind+m);
		REP(i,m+2) dp[i][0]=dp[i][1]=0;
		dp[1][0]=1;
		dp[1][1]=(ind[0]-1)/2;
		
		REPN(i,m,1){
			if(dp[i][0]>0){
				dp[i+1][0]+=dp[i][0];
				dp[i+1][1]+=dp[i][0]*((ind[i]-ind[i-1]-1)/2);
			}
			if(dp[i][1]>0){
				dp[i+1][0]+=dp[i][1];
				dp[i+1][1]+=dp[i][1]*((ind[i]-ind[i-1])/2);
			}
		}
		printf("%I64d\n",dp[m][0]+dp[m][1]);


	}	

		

	return 0;
}