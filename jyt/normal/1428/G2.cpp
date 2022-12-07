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
#define inf 1e18
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,K,val[9];ll f[N];
void Solve(ll w,ll v)
{
	for(int i=N-5;i>=w;i--) f[i]=max(f[i],f[i-w]+v);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<6;i++) scanf("%d",&val[i]);
	for(int i=1;i<=N-5;i++) f[i]=-inf;
	if(n>1)
	{
		for(int i=0,v=9,rem;i<6;v=v*10,i++)
		{
			rem=n-2;
			for(int j=0;1<<j<=rem;j++)
				Solve((ll)v*(1<<j),val[i]*3ll*(1<<j)),rem-=1<<j;
			Solve((ll)v*rem,val[i]*3ll*rem);
		}
		for(int i=0,v=1;i<6;v=v*10,i++)
			for(int j=N-5;j;j--)
			{
				if(j>=v*3) f[j]=max(f[j],f[j-v*3]+val[i]);
				if(j>=v*6) f[j]=max(f[j],f[j-v*6]+val[i]*2ll);
				if(j>=v*9) f[j]=max(f[j],f[j-v*9]+val[i]*3ll);
			}
	}
	for(int i=0,v=1;i<6;v=v*10,i++)
		for(int j=N-5;j;j--)
		{
			if(j>=v*3) f[j]=max(f[j],f[j-v*3]+val[i]);
			if(j>=v*6) f[j]=max(f[j],f[j-v*6]+val[i]*2ll);
			if(j>=v*9) f[j]=max(f[j],f[j-v*9]+val[i]*3ll);
			for(int k=1;k<9;k++) if(k^3&&k^6&&j>=v*k) f[j]=max(f[j],f[j-v*k]);
		}
	for(scanf("%d",&m);m--;) scanf("%d",&n),printf("%lld\n",f[n]);
	return 0;
}