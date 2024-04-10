#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int main()
{
	int T=read();
	while(T--)
	{
		ll n=read(),k=read(); k--;
		ll p1=k/n,p2=k%n;
		ll pa=n-p2+1; if(pa>n) pa-=n; //cout<<pa<<endl;
		ll pb=p2; if(pb==0) pb=n; //cout<<pb<<endl;
		pb=(pb+p1%n); if(pb>n) pb-=n;
		if(pb>=pa) pb++;
		if(pb>n) pb-=n;
		
		if(n%2==0)
		{
			ll ans=k%n+1; if(ans==0) ans=n;
			printf("%lld\n",ans);
		}
		else
		{
			ll tmp=n/2;
			if(k<tmp) {printf("%lld\n",k+1);}
			else
			{
				ll ans=tmp+2; k-=tmp;
				ll p2=k/tmp; ll pq=p2*(tmp+1)+k%tmp;
				pq%=n; ans=(ans+pq)%n; if(ans==0) ans+=n;
				printf("%lld\n",ans);
			}
		}
	}
	return 0;
}