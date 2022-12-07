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
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,A[N],f[N],sta1[N],sta2[N],top1,top2;
int main()
{
	scanf("%d",&n),f[0]=inf;
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	sta1[top1=1]=sta2[top2=1]=1;
	for(int i=2,flag1,flag2;i<=n;i++)
	{
		f[i]=f[i-1]+1,flag1=flag2=0;
		for(;A[sta1[top1]]<=A[i]&&top1;top1--)
			f[i]=min(f[i],f[sta1[top1]]+1),flag1|=A[sta1[top1]]==A[i];
		if(!flag1) f[i]=min(f[i],f[sta1[top1]]+1);
		for(;A[sta2[top2]]>=A[i]&&top2;top2--)
			f[i]=min(f[i],f[sta2[top2]]+1),flag2|=A[sta2[top2]]==A[i];
		if(!flag2) f[i]=min(f[i],f[sta2[top2]]+1);
		sta1[++top1]=i,sta2[++top2]=i;
	}
	printf("%d\n",f[n]);
	return 0;
}