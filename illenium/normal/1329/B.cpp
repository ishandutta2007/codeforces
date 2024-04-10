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

map <ll,ll> p;

int main()
{
	int T=read();
	while(T--)
	{
		ll d=read(),m=read(),l=2,r=3,ch=1; p.clear(); p[1]=1;
		if(d==1) {cout<<1%m<<endl; continue;}
		while(r<d)
		{
			p[l]=(p[l-1]*2+1)%m; ch=(p[l]-p[l-1]+m)%m;
			p[r]=(p[l-1]+(r-l+1)*ch)%m; ch=(p[r]-p[l-1]+m)%m;
			l=r+1; r=2*r+1;
		}
		p[l]=(p[l-1]*2+1)%m; ch=(p[l]-p[l-1]+m)%m;
		printf("%lld\n",((d-l)*ch+p[l])%m);
	}
	return 0;
}