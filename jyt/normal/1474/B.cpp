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
int T,n,cntp,pri[N],isp[N];
void doPrime(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!isp[i]) pri[++cntp]=i;
		for(int j=1;j<=cntp&&(ll)i*pri[j]<=n;j++)
		{
			isp[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
}
int main()
{
	doPrime(N-5);
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		for(int i=1,j=1;i<cntp;i++)
			if(pri[i]>n)
			{
				for(;j<=i||pri[j]-pri[i]<n;j++);
				printf("%lld\n",(ll)pri[i]*pri[j]);
				break;
			}
	}
	return 0;
}