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

ll p,b,q,n,t;

int main()
{
	ll T=read();
	while(T--)
	{
		p=read(); q=read(); b=read();
		ll g=__gcd(p,q); p/=g; q/=g; t=b;
		while(q!=1)
		{
			t=__gcd(q,t); if(t==1) break;
			q/=t;
		}
		if(q==1) puts("Finite");
		else puts("Infinite");
	}
	return 0;
}