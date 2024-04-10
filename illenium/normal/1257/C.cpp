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
#define maxn 200005
#define re register
#define inf 1e9+7
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int pre[maxn],a[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),ans=inf;
		for(int i=1;i<=n;i++) pre[i]=0;
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++)
		{
			if(pre[a[i]]==0) pre[a[i]]=i;
			else ans=min(ans,i-pre[a[i]]+1),pre[a[i]]=i;
		}
		if(ans==inf) puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}