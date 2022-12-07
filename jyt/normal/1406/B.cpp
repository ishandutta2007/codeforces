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
int T,n,An,Bn,Cn,A[N],B[N],C[N],flag;ll ans;
void work(int step,ll res,int cnt)
{
	if(step>Bn)
	{
		if(cnt==5) ans=max(ans,res);
		return;
	}
	work(step+1,res,cnt),work(step+1,res*B[step],cnt+1);
}
void clear()
{
	flag=Bn=Cn=ans=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n),ans=-1e18;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&A[i]),flag|=A[i]==0;
			if(A[i]>0) B[++Bn]=A[i];
			if(A[i]<0) C[++Cn]=A[i];
		}
		std::sort(B+1,B+1+Bn),std::reverse(B+1,B+1+Bn);
		std::sort(C+1,C+1+Cn);
		if(!Bn)
		{
			if(flag) {puts("0");continue;}
			else
			{
				ans=1;
				for(int i=1;i<6;i++) ans*=C[Cn-i+1];
			}
			printf("%lld\n",ans);continue;
		}
		Bn=min(Bn,5);
		for(int i=1;i<=min(Cn,5);i++) B[++Bn]=C[i];
		work(1,1,0);
		if(flag) printf("%lld\n",max(ans,0ll));
		else printf("%lld\n",ans);
	}
	return 0;
}