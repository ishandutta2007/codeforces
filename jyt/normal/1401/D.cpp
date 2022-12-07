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
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,a,b,A[N],ecnt,last[N],size[N],ans;ll val[N];
struct road{int to,nex;}e[N<<1];
void adde(int u,int v) {e[++ecnt]={v,last[u]},last[u]=ecnt;}
int cal(int x) {x-=x<mod?0:mod;return x;}
void dfs(int x,int fath=0)
{
	size[x]=1;
	for(int k=last[x];k;k=e[k].nex)
		if(e[k].to^fath) dfs(e[k].to,x),size[x]+=size[e[k].to];
	val[x]=(ll)size[x]*(n-size[x]);
}
void clear()
{
	ecnt=ans=0;
	for(int i=1;i<=n;i++) last[i]=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
		scanf("%d",&m);
		for(int i=1;i<=m;i++) scanf("%d",&A[i]);
		if(m<n-1) for(;m<n-1;) A[++m]=1;
		dfs(1);
		// for(int i=1;i<=n;i++) dbg1(i),dbg2(val[i]);
		std::sort(val+1,val+1+n),std::sort(A+1,A+1+m);
		for(int i=n;i<=m;i++) A[n-1]=(ll)A[n-1]*A[i]%mod;
		for(int i=1;i<n;i++) ans=cal(ans+(ll)A[i]*val[i+1]%mod);
		// else for(int i=1;i<=m;i++) ans=cal(ans+(ll)A[i]*val[n-m+i]%mod);
		printf("%d\n",ans);
	}
	return 0;
}