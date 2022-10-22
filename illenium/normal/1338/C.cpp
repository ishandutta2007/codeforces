#pragma GCC optimize(2)
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

ll d[maxn],p[maxn];

int main()
{
	int T=read(); d[0]=1; p[0]=1;
	for(int i=1;i<=30;i++) d[i]=d[i-1]*4,p[i]=p[i-1]+d[i];
	//for(int i=1;i<=4;i++) cout<<d[i]<<" "<<p[i]<<endl;
	while(T--)
	{
		ll x=read(),nw,ans=0,q=x/3+1,f=0;
		if(x%3==1)
		{
			nw=q;
			for(int i=0;i<=30;i++)
			{
				if(nw<=d[i]) {ans+=d[i]; break;}
				nw-=d[i]; ll p=(nw-1)/d[i];
				if(p%4==0) ;
				else if(p%4==1) ans+=d[i];
				else if(p%4==2) ans+=2*d[i];
				else if(p%4==3) ans+=3*d[i];
			}
		}
		
		else if(x%3==2)
		{
			nw=q;
			for(int i=0;i<=30;i++)
			{
				if(nw<=d[i]) {ans+=2*d[i]; break;}
				nw-=d[i]; ll p=(nw-1)/d[i];
				if(p%4==0) ;
				else if(p%4==1) ans+=2*d[i];
				else if(p%4==2) ans+=3*d[i];
				else if(p%4==3) ans+=d[i];
			}
		}
		
		else
		{
			q--; nw=q;
			for(int i=0;i<=30;i++)
			{
				if(nw<=d[i]) {ans+=3*d[i]; break;}
				nw-=d[i]; ll p=(nw-1)/d[i];
				if(p%4==0) ;
				else if(p%4==1) ans+=3*d[i];
				else if(p%4==2) ans+=d[i];
				else if(p%4==3) ans+=2*d[i];
			}
		}
		
		printf("%lld\n",ans);
	}
	return 0;
}