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
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,a,b,ecnt,last[N],size[N],Maxsz[N],fa[N],rt1,rt2,leaf[N],ans;
struct road{int to,nex;}e[N<<1];
void adde(int u,int v) {e[++ecnt]={v,last[u]},last[u]=ecnt;}
void getroot(int x,int fath=0)
{
	size[x]=1,Maxsz[x]=0,fa[x]=fath;
	for(int k=last[x];k;k=e[k].nex)
		if(e[k].to^fath)
		{
			getroot(e[k].to,x),size[x]+=size[e[k].to];
			Maxsz[x]=max(Maxsz[x],size[e[k].to]);
		}
	Maxsz[x]=max(Maxsz[x],n-size[x]);
	if(Maxsz[x]<Maxsz[rt1]||!rt1) rt1=x,rt2=0;
	else if(Maxsz[x]==Maxsz[rt1]) rt2=x;
}
void dfs(int x,int fath)
{
	fa[x]=fath;
	for(int k=last[x];k;k=e[k].nex)
		if(e[k].to^fath) dfs(e[k].to,x),leaf[x]=1;
	if(!leaf[x]) ans=x;
}
void clear()
{
	rt1=rt2=ans=0;
	for(int i=1;i<=n;i++) leaf[i]=last[i]=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
		getroot(1);
		if(!rt2)
		{
			printf("%d 2\n",fa[2]);
			printf("%d 2\n",fa[2]);
		}
		else
		{
			dfs(rt2,rt1);
			printf("%d %d\n",fa[ans],ans);
			printf("%d %d\n",rt1,ans);
			// dbg2(ans);
		}
		// dbg1(rt1),dbg2(rt2);
	}
	return 0;
}