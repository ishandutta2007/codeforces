#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
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

ll ans,a[maxn],pre[maxn],n,k,z;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); k=read(); z=read(); ll mx=0;
		rep(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
		ans=pre[k];
		rep(i,2,k+1)
		{
			ll tmp=pre[i],x=min(z,(k-i)/2+1);
			tmp+=a[i-1]*x+a[i]*(x-1);
			tmp+=pre[k-2*x+1]-pre[i-1];
			ans=max(ans,tmp);
		}
		printf("%lld\n",ans);
	}
	return 0;
}