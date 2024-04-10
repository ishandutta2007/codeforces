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

int main()
{
	int T=read();
	while(T--)
	{
		int x=read(),tmp=sqrt(x);
		if(tmp*tmp==x) printf("%d %d\n",tmp,1);
		else
		{
			int y=x-tmp*tmp;
			if(y<=tmp+1) printf("%d %d\n",y,tmp+1);
			else printf("%d %d\n",tmp+1,tmp+1-(y-tmp-1));
		}
	}
	return 0;
}