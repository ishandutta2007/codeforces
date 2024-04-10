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

int n,a[maxn],pre[maxn];

inline int get(int l,int r){return pre[r]^pre[l-1];}

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),pre[i]=pre[i-1]^a[i];
	if(n>=1000) return puts("1"),0;
	int ans=inf;
	rep(i,2,n)
	{
		for(int l=i-1,c1=0;c1<=30,l>=1;l--,c1++)
		{
			for(int r=i,c2=0;c2+c1<=30,r<=n;r++,c2++)
			{
				if(c1+c2>=ans) break;
				if(get(l,i-1)>get(i,r)) ans=min(ans,c1+c2);
			}
		}
	}
	if(ans==inf) puts("-1"); else printf("%d\n",ans);
	return 0;
}