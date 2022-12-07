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
int T,n,A[N],a,b,deg[N],id[N];ll ans[N];
void clear()
{
	for(int i=1;i<=n;i++) deg[i]=ans[i]=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&A[i]),id[i]=i,ans[1]+=A[i];
		for(int i=1;i<n;i++) scanf("%d%d",&a,&b),deg[a]++,deg[b]++;
		std::sort(id+1,id+1+n,[](int t1,int t2){return A[t1]>A[t2];});
		for(int i=2,j=1;i<n;i++)
		{
			for(;deg[id[j]]==1;j++);
			ans[i]=ans[i-1]+A[id[j]],deg[id[j]]--;
		}
		for(int i=1;i<n;i++) printf("%lld ",ans[i]);puts("");
	}
	return 0;
}