#pragma GCC optimize(2)
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

int main()
{
	int T=read();
	while(T--)
	{
		ll a=read(),b=read(); ll tmp=abs(a-b);
		for(ll i=0;;i++)
		{
			ll tmp2=(i*(i+1))/2;
			if(tmp2<tmp) continue;
			if((tmp2-tmp)%2==0) {printf("%lld\n",i); break;}
		}
	}
	return 0;
}