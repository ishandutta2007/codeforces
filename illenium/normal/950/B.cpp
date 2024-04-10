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
#define maxn 100005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,m,ans;
ll a[maxn],b[maxn],sa[maxn],sb[maxn];

int main()
{
	n=read(); m=read();
	for(int i=1;i<=n;i++) a[i]=read(),sa[i]=sa[i-1]+a[i];
	for(int i=1;i<=m;i++) b[i]=read(),sb[i]=sb[i-1]+b[i];
	ll la=0,lb=0,nowj=0;
	for(int i=1;i<=n;i++)
	{
		ll t=sa[i]-sa[la];
		ll t2=sb[nowj]-sb[lb];
		while(t2<t)
		{
			nowj++;
			t2=sb[nowj]-sb[lb];
		}
		if(t2==t) {ans++; continue;}
	}
	cout<<ans;
	return 0;
}