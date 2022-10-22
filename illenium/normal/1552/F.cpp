#pragma GCC optimize("O3")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,l[maxn],r[maxn],e[maxn],b[maxn],a[maxn],ans;
const ll mod=998244353;

int main()
{
	n=read(); rep(i,1,n) l[i]=read(),r[i]=read(),e[i]=read(); l[n+1]=l[n]+1; a[0]=l[1];
	rep(i,1,n)
	{
		int L=0,R=n,x=0;
		while(L<=R)
		{
			int mid=(L+R)>>1;
			if(l[mid]>r[i]) x=mid,R=mid-1;
			else L=mid+1;
		}
		b[i]=x;
	}
	rep(i,1,n) a[i]=(a[i-1]+l[b[i]]-r[i]+a[i-1]-a[b[i]-1]+l[i+1]-l[i]+3*mod)%mod;
	rep(i,1,n)
	{
		if(e[i]) ans=(ans+(a[i]-a[i-1])+mod)%mod;
		else ans=(ans+(l[i+1]-l[i])+mod)%mod;
	}
	printf("%lld\n",(ans+l[1])%mod);
	return 0;
}