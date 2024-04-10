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

const int maxn=(1<<22)+10;
int dp[maxn],last[maxn],opt[maxn],val[maxn],ans[25],n,m;

inline void bfs()
{
	memset(last,-1,sizeof(last));
	memset(opt,-1,sizeof(opt));
	queue <int> q;
	for(int i=0;i<n;i++)
	{
		dp[val[i]]=1;
		opt[val[i]]=i;
		q.push(val[i]);
	}
	while(!q.empty())
	{
		int now=q.front(); q.pop();
		for(int i=0;i<n;i++)
		{
			if(now&(1<<i))
			{
				int tmp=now|val[i];
				if(dp[tmp]==0)
				{
					dp[tmp]=dp[now]+1;
					opt[tmp]=i;
					last[tmp]=now;
					q.push(tmp);
					if(tmp==(1<<n)-1) return;
				}
			}
		}
	}
}

int main()
{
	n=read(); m=read();
	for(int i=0;i<n;i++) val[i]|=(1<<i);
	for(int i=0;i<m;i++)
	{
		int a=read(),b=read(); a--; b--;
		val[a]|=(1<<b);
		val[b]|=(1<<a);
	}
	if(m==n*(n-1)/2){puts("0"); return 0;}
	bfs();
	int tmp=(1<<n)-1,mount=0;
	while(tmp!=-1)
	{
		ans[mount++]=opt[tmp];
		tmp=last[tmp];
	}
	printf("%d\n",mount);
	for(int i=mount-1;i>=0;i--) printf("%d ",ans[i]+1);
	return 0;
}