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
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,K,X,Y,f[N],ans;
char s[N];
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%d%d%s%d%d",&n,&m,&K,s+1,&X,&Y),ans=inf;
		for(int i=n;i;i--)
		{
			if(i+K<=n) f[i]=f[i+K];
			else f[i]=0;
			// dbg1(i+K),dbg2(f[i]);
			if(s[i]=='0') f[i]+=X;
			// if(i<n) f[i]=min(f[i],f[i+1]+Y);
			// dbg1(i),dbg2(f[i]);
		}
		// for(int i=1;i<=m;i++) ans=min(ans,f[i]+(m-i)*Y);
		for(int i=m;i<=n;i++) ans=min(ans,f[i]+(i-m)*Y);
		printf("%d\n",ans);
	}
	return 0;
}