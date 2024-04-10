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
 
inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}
 
ll n,m;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(),m=read(); int ans=0,F=0;
		for(int i=30;i>=0;i--)
		{
			if((n&(1<<i))&&(!(m&(1<<i)))) F=1;
			if(F==0&&!(n&(1<<i))&&((m&(1<<i)))) ans|=(1<<i);
		}
		if(!F)
		{
			for(int i=0;i<=30;i++)
			{
				if(!(n&(1<<i))&&(m&(1<<i))) ans^=(1<<i);
				if(!(m&(1<<i))) {ans|=(1<<i); break;}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}