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
#define N 300005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,a,b,ecnt,last[N],mark[N],flag,ans[N];
struct road{int to,nex;}e[N<<1];
void adde(int u,int v) {e[++ecnt]=(road){v,last[u]},last[u]=ecnt;}
void dfs(int x)
{
	if(mark[x]) return;
	int cnt=0;
	for(int k=last[x];k;k=e[k].nex) cnt+=mark[e[k].to]==1;
	mark[x]=cnt?2:1;
	for(int k=last[x];k;k=e[k].nex) dfs(e[k].to);
}
void clear()
{
	for(int i=1;i<=n;i++) last[i]=mark[i]=0;
	ecnt=flag=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
		dfs(1);
		for(int i=1;i<=n;i++) if(!mark[i]) flag=1;
		if(flag) {puts("NO");continue;}
		for(int i=1;i<=n;i++) if(mark[i]==1) ans[++ans[0]]=i;
		printf("YES\n%d\n",ans[0]);
		for(;ans[0];) printf("%d ",ans[ans[0]--]);
		puts("");
	}
	return 0;
}