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
ll a,b,tmp,ans;
int T,pri[N],isp[N],cntp,An,A[N];
void doPrime(int x)
{
	for(int i=2;i<=x;i++)
	{
		if(!isp[i]) pri[++cntp]=i;
		for(int j=1;j<=cntp&&(ll)i*pri[j]<=x;j++)
		{
			isp[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}
int main()
{
	doPrime(N-5);
	for(scanf("%d",&T);T--;An=ans=0)
	{
		scanf("%lld%lld",&a,&b),tmp=b;
		if(a%b) {printf("%lld\n",a);continue;}
		for(int i=1;i<=cntp&&(ll)pri[i]*pri[i]<=b;i++)
		{
			if(b%pri[i]==0)
			{
				A[++An]=pri[i];
				for(;b%pri[i]==0;b/=pri[i]);
			}
		}
		if(b>1) A[++An]=b;
		for(int i=1;i<=An;i++)
		{
			ll v=a;
			for(;v%tmp==0;v/=A[i]);
			ans=max(ans,v);
		}
		printf("%lld\n",ans);
	}
	return 0;
}