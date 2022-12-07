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
#define N 500005
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,cnt[65],ans;ll A[N];
int cal(int x) {x-=x<mod?0:mod;return x;}
void clear()
{
	for(int i=0;i<60;i++) cnt[i]=0;
	ans=0;
	// for(int i=1;i<=n;i++) Sum1[i]=Sum2[i]=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&A[i]);
		/*
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				Sum1[i]=(Sum1[i]+(A[i]&A[j]))%mod,Sum2[i]=(Sum2[i]+(A[i]|A[j]))%mod;
		for(int i=1;i<=n;i++) ans=(ans+(ll)Sum1[i]*Sum2[i])%mod;
		*/
		for(int i=1;i<=n;i++)
			for(int j=0;j<60;j++) cnt[j]+=A[i]>>j&1;
		for(int i=1,v1,v2;i<=n;i++)
		{
			v1=v2=0;
			for(int j=0;j<60;j++)
			{
				if(A[i]>>j&1) v1=(v1+(1ll<<j)%mod*cnt[j])%mod,v2=(v2+(1ll<<j)%mod*n)%mod;
				else v2=(v2+(1ll<<j)%mod*cnt[j])%mod;
			}
			ans=(ans+(ll)v1*v2)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}