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

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],b[maxn],tot;

int main()
{
	ll T=read();
	while(T--)
	{
		ll n=read(),r=read(),cnt=0,t=0;
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		tot=unique(a+1,a+n+1)-a-1;
		for(int i=tot;i>=0;i--)
		{
			if(a[i]<=cnt) {cout<<t<<endl; break;}
			else cnt+=r,t++;
		}
	}
	return 0;
}