#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int main()
{
	int T=read();
	while(T--)
	{
		ll n=read(),m=read(),p=0;
		ll tmp=n,res=0;
		if(2*m+1<n)
		{
			ll x=((n+1)/(m+1)); //cout<<x<<endl;
			ll p1=m*(x+1)*x/2; //cout<<p1<<endl;
			ll p2=(n-x)*(n-x+1)/2; //cout<<p2<<endl;
			p2+=p1; p=p2;
		}
		else
		{
			p=n*(n-1)/2;
			p+=m;
		}
		printf("%lld\n",p);
	}
	return 0;
}