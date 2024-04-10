#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const ll mod=1000000007;
const int maxn=200;
const int inf=0x3f3f3f3f;
const int INF=0x7f7f7f7f;
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
#define ms(a) memset(a,0,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define msi(a) memset(a,inf,sizeof(a))
#define iossync ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
// head
ll pow_(ll x,ll y)
{
    ll rt=1;
    while (y){
        if (y&1) rt=rt*x%mod;
        x=x*x%mod; y>>=1;
    }
    return rt;
}
//unsigned 
ll dp[maxn][maxn][maxn],n,m,len[maxn];
string s1;
void init()
{
	#define num len
	num[0]=2;
	num[1]=2;
	rep(i,2,m+1)
	num[i]=num[i-1]*num[i-2]%mod;
	#undef num
}
int main()
{
	
	cin>>n>>m;
	init();//2^len 
	cin>>s1;
	rep(i,1,n+1)
	{//l==r
		dp[s1[i-1]-'0'][i][i]=1;
		//10 
	}
	rep(i,2,m+1)
	{
		rep(l,1,n+1)
		{
			rep(r,l,n+1)
			{
				// 
//				dp[i][l][r]+=dp[i-1][l][r]+dp[i-2][l][r];
				if(r==n)//r 
				(dp[i][l][r]+=dp[i-1][l][r]*len[i-2]%mod)%=mod;
				else
				(dp[i][l][r]+=dp[i-1][l][r])%=mod;
				if(l==1)//l 
				(dp[i][l][r]+=dp[i-2][l][r]*len[i-1])%=mod;
				else
				(dp[i][l][r]+=dp[i-2][l][r])%=mod;
				rep(k,l,r)
				{
					(dp[i][l][r]+=dp[i-1][l][k]*dp[i-2][k+1][r])%=mod;
				 } 
			}
		}
	}
	cout<<dp[m][1][n]<<"\n";
	return 0;
}