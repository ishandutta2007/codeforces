#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 400005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,a,b,ecnt,last[N],dist[N],deg[N],mark[N],ans;
std::queue<int>Q,Q2;
struct road{int to,nex;}e[N<<1];
void adde(int u,int v) {e[++ecnt]=(road){v,last[u]},last[u]=ecnt,deg[u]++;}
void dfs(int x,int fath=0)
{
	int son=0;
	for(int k=last[x];k;k=e[k].nex)
		if(e[k].to^fath) dfs(e[k].to,x),son++;
	if(!son||!fath&&son==1) Q.push(x),dist[x]=1;
}
void clear()
{
	for(int i=1;i<=n;i++) last[i]=dist[i]=deg[i]=mark[i]=0;
	ecnt=ans=0;
	for(;!Q.empty();Q.pop());
	for(;!Q2.empty();Q2.pop());
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<n;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
		if(n==1)
		{
			puts(m?"0":"1");
			continue;
		}
		// dfs(1);
		for(int i=1;i<=n;i++) if(deg[i]==1) Q.push(i);
		for(int i=1;i<=m&&!Q.empty();i++)
		{
			for(int top;!Q.empty();)
			{
				top=Q.front(),Q.pop(),mark[top]=1;
				for(int k=last[top];k;k=e[k].nex)
				{
					deg[e[k].to]--;
					if(deg[e[k].to]==1) Q2.push(e[k].to);
				}
				// dbg1(i),dbg2(top);
			}
			for(;!Q2.empty();Q2.pop()) Q.push(Q2.front());
		}
		for(int i=1;i<=n;i++) if(!mark[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}