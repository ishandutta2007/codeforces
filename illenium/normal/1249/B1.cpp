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

int f[maxn],cnt,ans[maxn];

inline int getf(int x)
{
	if(f[x]==x) return x;
	return f[x]=getf(f[x]);
}

inline void merge(int a,int b)
{
	int fa=getf(a),fb=getf(b);
	if(fa==fb) return;
	f[fa]=fb;
	return;
}

int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++) f[i]=i;
		for(int i=1;i<=n;i++)
		{
			int x=read();
			merge(x,i);
		}
		for(int i=1;i<=n;i++)
		{
			int x=getf(i);
			ans[x]++;
		}
		for(int i=1;i<=n;i++)
		{
			int x=getf(i);
			printf("%d ",ans[x]);
		}
		puts("");
		memset(ans,0,sizeof(ans));
	}
	return 0;
}