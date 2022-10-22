#pragma GCC optimize(2)
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
		ll a=read(),b=read(),c=read(),cnt=0; if(a>b) swap(a,b);
		if(a>c||b>c) {puts("0"); continue;}
		while(a+b<=c)
		{
			a+=b;
			swap(a,b); cnt++;
		}
		printf("%d\n",cnt+1);
	}
	return 0;
}