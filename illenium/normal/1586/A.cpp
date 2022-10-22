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

bool is[maxn];
int pri[maxn],cnt,pos[maxn],n,a[maxn],tt;

inline void pre()
{
	for(int i=2;i<=maxn-5;i++)
	{
		if(!is[i]) pri[++cnt]=i,pos[i]=cnt;
		for(int j=1;j<=cnt;j++)
		{
			int k=pri[j]*i; if(k>maxn-5) break; is[k]=1;
			if(i%pri[j]==0) break;
		}
	}
}

int main()
{
	int T=read(); pre();
	while(T--)
	{
		n=read(); tt=0; rep(i,1,n) a[i]=read(),tt+=a[i];
		if(!is[tt])
		{
			int F=0;
			rep(i,1,n) if(is[tt-a[i]]) {F=i; break;}
			printf("%d\n",n-1);
			rep(i,1,n) if(i!=F) printf("%d ",i); puts("");
		}
		else
		{
			printf("%d\n",n);
			rep(i,1,n) printf("%d ",i); puts("");
		}
	}
	return 0;
}