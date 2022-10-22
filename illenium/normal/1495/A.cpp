#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
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

ll n;

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); vector <ll> vx,vy; vx.clear(); vy.clear();
		rep(i,1,2*n)
		{
			int u=read(),v=read();
			if(!u) vx.pb(abs(v)); else vy.pb(abs(u));
		}
		sort(vx.begin(),vx.end()); sort(vy.begin(),vy.end());
		long double ans=0;
		rep(i,0,n-1) ans+=sqrt(vx[i]*vx[i]+vy[i]*vy[i]);
		printf("%.10Lf\n",ans);
	}
	return 0;
}