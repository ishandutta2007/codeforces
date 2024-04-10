#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 10000005
#define N 200005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

bool is[maxn];
ll pri[maxn],cnt;

inline void pre()
{
	for(int i=2;i<=maxn-5;i++)
	{
		if(!is[i]) pri[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			int k=pri[j]*i; if(k>maxn-5) break; is[k]=1;
			if(i%pri[j]==0) break;
		}
	}
}

ll n,k,a[N];
map <ll,ll> p;

int main()
{
	int T=read(); pre();
	while(T--)
	{
		n=read(),k=read(); rep(i,1,n) a[i]=read();
		rep(i,1,n) for(int j=1;pri[j]*pri[j]<=a[i]&&j<=cnt;j++)
		{
			if(a[i]%(pri[j]*pri[j])==0)
			{
				while(a[i]%(pri[j]*pri[j])==0) a[i]/=(pri[j]*pri[j]);
			}
		}
		int ans=0; p.clear();
		rep(i,1,n)
		{
			if(p[a[i]]) ans++,p.clear(),p[a[i]]=1;
			else p[a[i]]++;
		}
		printf("%d\n",ans+1);
	}
	return 0;
}