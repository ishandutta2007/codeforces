#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
#define p 998244353
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a,b,c,dp[5005][5005];

int main()
{
	cin>>a>>b>>c;
	for(int i=0;i<=5000;i++) dp[0][i]=1,dp[i][0]=1;
	for(int i=1;i<=5000;i++)
	{
		for(int j=1;j<=5000;j++)
			dp[i][j]=(dp[i-1][j]+(dp[i-1][j-1]*j)%p)%p;
	}
	cout<<((dp[a][b]*dp[b][c])%p*dp[a][c])%p<<endl;
	return 0;
}