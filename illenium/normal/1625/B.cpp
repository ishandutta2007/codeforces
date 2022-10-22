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

int n,a[maxn];
vector <int> pos[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int ans=inf;
		n=read(); rep(i,1,n) a[i]=read(),pos[a[i]].pb(i);
		rep(i,1,150000)
		{
			if(pos[i].size()==1)  continue;
			for(int j=1;j<pos[i].size();j++) ans=min(ans,pos[i][j]-pos[i][j-1]);
		}
		if(ans==inf) puts("-1");
		else printf("%d\n",n-ans);
		rep(i,1,150000) pos[i].clear();
	}
	return 0;
}