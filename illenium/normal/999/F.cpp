#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn],cnt[maxn],f[maxn],h[maxn],dp[5005][505];
int n,k,c,num[maxn];

int main()
{
	n=read(); k=read();
	for(int i=1;i<=n*k;i++) a[i]=read(),cnt[a[i]]++;
	for(int i=1;i<=n;i++) f[i]=read(),num[f[i]]++;
	for(int i=1;i<=k;i++) h[i]=read();
	for(int i=1;i<=n*k;i++)
	{
		dp[i][1]=h[min(i,k)];
		for(int j=2;j<=n;j++)
		{
			for(int u=1;u<=min(i,k);u++)
				dp[i][j]=max(dp[i][j],dp[i-u][j-1]+h[u]);
		}
	}
	ll ans=0;
	for(int i=0;i<=1e5;i++) if(num[i]) ans+=dp[cnt[i]][num[i]];
	cout<<ans<<endl;
	return 0;
}