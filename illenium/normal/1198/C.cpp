#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 500005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int f[maxn],ans[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),m=read(),cnt=0,cnt2=0;
		for(int i=1;i<=3*n;i++) f[i]=0;
		for(int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			if(!f[u]&&!f[v]) f[u]=1,f[v]=1,ans[++cnt]=i;
		}
		if(cnt>=n)
		{
			puts("Matching");
			for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		}
		else
		{
			puts("IndSet");
			for(int i=1;i<=3*n;i++)
			{
				if(!f[i]) cnt2++,printf("%d ",i);
				if(cnt2==n) break;
			}
		}
		printf("\n");
	}
	return 0;
}