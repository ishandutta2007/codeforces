#pragma GCC optimize(2)
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

int a[maxn],c[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read(),ans=inf; rep(i,1,n) a[i]=read();
		rep(i,1,n/2)
		{
			int x=a[i],y=a[n-i+1];
			int l=min(x+1,y+1),r=max(x+k,y+k);
			c[l]++; c[r+1]--; c[x+y]--; c[x+y+1]++;
			c[1]+=2; c[l]-=2; c[r+1]+=2; c[2*k+1]-=2;
		}
		int nw=0;
		rep(i,1,2*k)
		{
			nw+=c[i];
			ans=min(ans,nw);
		}
		cout<<ans<<endl;
		
		rep(i,0,2*k+1) c[i]=0;
	}
	return 0;
}