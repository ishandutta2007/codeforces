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
#define N 1005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,cnt[N],cntp,pri[N],isp[N];
char s[N];
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
void Solve()
{
	for(int i=4;i<=9;i+=2) if(cnt[i]) {printf("1\n%d\n",i);return;}
	if(cnt[1]) {puts("1\n1");return;}
	if(cnt[9]) {puts("1\n9");return;}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(isp[(s[i]-48)*10+s[j]-48])
			{
				printf("2\n%d%d\n",s[i]-48,s[j]-48);
				return;
			}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			for(int k=j+1;k<=n;k++)
				if(isp[(s[i]-48)*100+(s[j]-48)*10+s[k]-48])
				{
					printf("3\n%d%d%d\n",s[i]-48,s[j]-48,s[k]-48);
					return;
				}
}
void clear()
{
	for(int i=0;i<=9;i++) cnt[i]=0;
}
int main()
{
	doPrime(N-5);
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;i++) cnt[s[i]-48]++;
		Solve();
		// printf("%d\n",Solve());
		// for(int i=1;i<=n;i++)
			// if(cnt[s[i]-48]) cnt[s[i]-48]--;else printf("%d",s[i]-48);
	}
	return 0;
}