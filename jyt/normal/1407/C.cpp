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
#define N 10005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,p1,p2,a,b,ans[N],mark[N];
int main()
{
	scanf("%d",&n),p1=1,p2=2;
	for(int i=1;i<n;i++)
	{
		if(p1>p2) std::swap(p1,p2);
		for(;ans[p1];p1++);
		for(;ans[p2]||p2<=p1;p2++);
		printf("? %d %d\n",p1,p2),fflush(stdout),scanf("%d",&a);
		printf("? %d %d\n",p2,p1),fflush(stdout),scanf("%d",&b);
		if(a<b) std::swap(a,b),std::swap(p1,p2);
		ans[p1]=a,mark[a]=1;
	}
	for(int i=1;i<=n;i++) if(!mark[i]) a=i;
	for(int i=1;i<=n;i++) if(!ans[i]) ans[i]=a;
	printf("!");
	for(int i=1;i<=n;i++) printf(" %d",ans[i]);
	return 0;
}