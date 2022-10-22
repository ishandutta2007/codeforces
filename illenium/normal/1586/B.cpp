#pragma GCC optimize("O3")
#pragma GCC target("avx2")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define ins insert
#define pb push_back
#define vi vector <int>
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

inline void write(ll x)
{
	if(x<0) {putchar('-'); return write(-x);}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

int n,m,v[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read(); rep(i,1,n) v[i]=0;
		rep(i,1,m)
		{
			int a=read(),b=read(),c=read(); v[b]=1;
		}
		int F=0;
		rep(i,1,n) if(!v[i]) {F=i; break;}
		rep(i,1,n) if(i!=F) printf("%d %d\n",i,F);
	}
	return 0;
}