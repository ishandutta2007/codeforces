#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
ll dp[110][110][110];
ll p;
ll C[110][110];
double st;
ll calc(const int &i,const int &j,const int &kk)
{
	if(dp[i][j][kk]!=-1)
		return dp[i][j][kk];
	if(j+kk>i+50)
		return 0;
	if(j<=1)
		return 0;
    if(clock()-st>1980)
        die("0");
	ll ans=0;
	for(int l=1;l<=i;l++)
		for(int o=0;o<=min(l,kk);o++)
		{
		    ll a=calc(l-1,j-1,o);
		    ll b=calc(i-l,j-1,kk-o);
		    a*=b;
		    a%=p;
		    a*=C[i-1][l-1];
		    a%=p;
		    ans+=a;
		}
    ans%=p;
	return dp[i][j][kk]=ans;
}
int main()
{
    st=clock();
	memset(dp,-1,sizeof(dp));
	int n,m,k;
	cin>>n>>m>>k>>p;
//	swap(m,k);
	C[0][0]=1;
	for(int i=1;i<110;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%p;
//			cout<<i<<" "<<j<<" "<<C[i][j]<<endl;
		}
	}
	for(int i=0;i<110;i++)
		dp[0][i][0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][1][1]=1;
		for(int j=1;j<=i;j++)
			dp[i][1][1]=dp[i][1][1]*j%p;
	}
	cout<<calc(n,m,k)<<endl;
	return 0;
}