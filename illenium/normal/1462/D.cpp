#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int a[maxn],tot,n;

inline bool jud(int x)
{
	int nw=0;
	rep(i,1,n)
	{
		nw+=a[i];
		if(nw==x) nw=0;
		else if(nw>x) return false;
	}
	return true;
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); tot=0; int ans=0; rep(i,1,n) a[i]=read(),tot+=a[i];
		per(i,n,1) if(tot%i==0)
		{
			if(jud(tot/i)) {ans=i; break;}
		}
		printf("%d\n",n-ans);
	}
	return 0;
}