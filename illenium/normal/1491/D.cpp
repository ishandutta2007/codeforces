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

ll s[maxn],t[maxn],ts,tt,cnts,cntt;

int main()
{
	int T=read();
	while(T--)
	{
		ll u=read(),v=read(); cnts=0; cntt=0;
		if(u>v) {puts("NO"); continue;}
		rep(i,0,40) s[i]=0,t[i]=0;
		while(u) s[++cnts]=(u&1),u>>=1;
		while(v) t[++cntt]=(v&1),v>>=1;
		int ts=0,tt=0,F=0;
		rep(i,1,cntt)
		{
			ts+=s[i]; tt+=t[i];
			if(ts<tt) {F=1; break;}
		}
		if(F) puts("NO"); else puts("YES");
	}
	return 0;
}