#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
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
lint dp[100][100];

lint gett(int h,int p,lint n){
	if(n==0 || p<0) return 0;
	if((1ll<<h)<=n) return dp[h][p];
	lint half=(1ll<<(h-1));
	if(n<=half) return gett(h-1,p,n);
	else return gett(h-1,p,half)+gett(h-1,p-1,n-half);
}

lint solve(lint n,int p){
	lint sum=1;
	int h=1;
	lint res=0;
	while(sum<n){
		res+=gett(h,p,n-sum);
		sum+=(1ll<<h);
		++h;
	}
	return res;
}
int main(){
	dp[0][0]=1;
	REP(i,50) REP(j,50) dp[i+1][j]=dp[i][j]+(j>=1?dp[i][j-1]:0);
	

	lint n,t;
	cin>>n>>t;
	++n;

	int p=0;
	while((1ll<<p)<t) ++p;
	if((1ll<<p)!=t){
		puts("0");
		return 0;
	}
	cout<<solve(n,p)<<endl;
	return 0;
}