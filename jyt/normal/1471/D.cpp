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
#define N 1000005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,A[N],cntp,pri[N],isp[N],Minp[N],cnt[N],Max,ans0,ans1,ans2;ll a;
void doPrime(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!isp[i]) pri[++cntp]=i,Minp[i]=i;
		for(int j=1;j<=cntp&&(ll)i*pri[j]<=n;j++)
		{
			isp[i*pri[j]]=1,Minp[i*pri[j]]=pri[j];
			if(i%pri[j]==0) break;
		}
	}
}
void clear()
{
	ans0=ans1=ans2=0;
	for(int i=1;i<=n;i++) cnt[A[i]]=0;
}
int main()
{
	doPrime(N-5);
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1,now;i<=n;i++)
		{
			scanf("%d",&A[i]),now=A[i],A[i]=1;
			for(int tmp,v;now>1;)
			{
				for(tmp=Minp[now],v=0;Minp[now]==tmp;now/=tmp,v++);
				if(v&1) A[i]*=tmp;
			}
			cnt[A[i]]++,Max=max(Max,A[i]),ans0=max(ans0,cnt[A[i]]);
		}
		ans1=cnt[1],cnt[1]=0;
		for(int i=1;i<=n;i++) if(cnt[A[i]]%2==0) ans1+=cnt[A[i]],cnt[A[i]]=0;
		ans1=max(ans0,ans1);
		for(scanf("%d",&m);m--;)
		{
			scanf("%lld",&a);
			if(a==0) printf("%d\n",ans0);
			else printf("%d\n",ans1);
		}
	}
	return 0;
}