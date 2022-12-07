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
#define mod 998244353
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,a,b,ecnt,last[N],flag,ans[N];
struct road{int to,nex;}e[N<<1];
void adde(int u,int v) {e[++ecnt]=(road){v,last[u]},last[u]=ecnt;}
int cal(int x) {x-=x<mod?0:mod;return x;}
int Pow(int x,int y) {int res=1;for(;y;x=(ll)x*x%mod,y>>=1) if(y&1) res=(ll)res*x%mod;return res;}
bool dfs(int x,int fath,int val)
{
	int cnt=fath>0;
	for(int k=last[x];k;k=e[k].nex)
		if(e[k].to^fath) cnt+=dfs(e[k].to,x,val);
	if(cnt%val==0) return 0;
	if(cnt%val&&fath) cnt--;
	if(cnt%val) flag=1;
	return 1;
}
void clear()
{
	for(int i=1;i<=n;i++) last[i]=ans[i]=0;
	ecnt=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n),ans[1]=Pow(2,n-1);
		for(int i=1;i<n;i++) scanf("%d%d",&a,&b),adde(a,b),adde(b,a);
		for(int i=2;i<n;i++) if((n-1)%i==0) flag=0,dfs(1,0,i),ans[i]=!flag;
		for(int i=n-1;i;i--)
			for(int j=i+i;j<=n;j+=i) ans[i]=cal(ans[i]-ans[j]+mod);
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");
	}
	return 0;
}