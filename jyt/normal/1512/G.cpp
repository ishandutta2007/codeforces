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
using std::make_pair;
#define N 10000005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,mark[N];
int cntp,pri[N],isp[N],mul[N];ll d[N];
// std::vector<std::pair<int,int>>S;
void doPrime(int n)
{
	d[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!isp[i]) pri[++cntp]=i,d[i]=i+1,mul[i]=i;
		for(int j=1;j<=cntp&&(ll)i*pri[j]<=n;j++)
		{
			isp[i*pri[j]]=1;
			if(i%pri[j]) d[i*pri[j]]=d[i]*d[pri[j]],mul[i*pri[j]]=pri[j];
			else
			{
				mul[i*pri[j]]=mul[i]*pri[j];
				d[i*pri[j]]=d[i/mul[i]]*((ll)mul[i*pri[j]]*pri[j]-1)/(pri[j]-1);
				break;
			}
		}
		// if(i<20) dbg1(i),dbg2(d[i]);
	}
	mark[1]=1;
	for(int i=1;i<=n;i++)
		if(d[i]<=N-5&&!mark[d[i]]) mark[d[i]]=i;
}
int main()
{
	doPrime(N-5);
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		printf("%d\n",mark[n]?mark[n]:-1);
	}
	return 0;
}