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
		ll a=read(),b=read();
		if((b%2==0&&a%2==1)||(b%2==1&&a%2==0)) puts("NO");
		else
		{
			ll tmp=b*b;
			if(tmp<=a) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}