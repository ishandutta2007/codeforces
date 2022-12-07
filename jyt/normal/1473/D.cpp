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
#define N 200005
#define inf 1e9
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,m,a,b,Sum[N],Max1[N],Max2[N],Min1[N],Min2[N],Max,Min;
char s[N];
void clear()
{
	for(int i=1;i<=n;i++) Max1[i]=Min1[i]=Max2[i]=Min2[i]=0;
}
int main()
{
	for(scanf("%d",&T);T--;clear())
	{
		scanf("%d%d%s",&n,&m,s+1);
		Max2[n+1]=-inf,Min2[n+1]=inf;
		for(int i=1;i<=n;i++)
		{
			Sum[i]=Sum[i-1]+(s[i]=='+'?1:-1);
			Max1[i]=max(Max1[i-1],Sum[i]);
			Min1[i]=min(Min1[i-1],Sum[i]);
		}
		for(int i=n;i;i--) Max2[i]=max(Max2[i+1],Sum[i]),Min2[i]=min(Min2[i+1],Sum[i]);
		for(;m--;)
		{
			scanf("%d%d",&a,&b),a--,b++,Max=Min=0;
			Max=max(Max1[a],Sum[a]+Max2[b]-Sum[b-1]),Min=min(Min1[a],Sum[a]+Min2[b]-Sum[b-1]);
			printf("%d\n",Max-Min+1);
		}
	}
	return 0;
}