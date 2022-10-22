#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[105],d,ans=inf,n,k,j;

int main()
{
	n=read(); k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++) if(a[j]-a[i]>k) break;
		ans=min(ans,n-(j-i));
	}
	cout<<ans;
	return 0;
}