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
#define maxn 1000005
#define re register
#define inf 1e16
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,m,k,s[maxn],a[maxn];
bool vis[maxn];

int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		ll x=read();
		vis[x]=1;
	}
	for(int i=1;i<=k;i++) a[i]=read();
	if(vis[0]) {puts("-1"); return 0;}
	ll len=0,ans=inf;
	for(int i=0;i<=n;i++)
	{
		if(vis[i]) s[i]=s[i-1]+1;
		else s[i]=0;
		len=max(len,s[i]);
	}
	for(int i=len+1;i<=k;i++)
	{
		ll cnt=0;
		for(int j=0;j<n;j+=i)
		{
			if(vis[j]) j-=s[j];
			cnt++;
		}
		ans=min(ans,a[i]*cnt);
	}
	if(ans>=inf) puts("-1");
	else cout<<ans<<endl;
	return 0;
}