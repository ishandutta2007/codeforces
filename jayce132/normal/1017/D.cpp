#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

const int maxn=20;

int n,m,q,w[maxn];

char str[maxn];
int all[1<<12];
int ans[1<<12][120];

inline void init()
{
	n=read();m=read();q=read();
	REP(i,1,n)w[i]=read();
	REP(i,1,m)
	{
		scanf("%s",str+1);
		int s=0;
		REP(j,1,strlen(str+1))s+=(str[j]-'0')<<j-1;
		all[s]++;
	}
	REP(i,0,(1<<n)-1)
	{
		REP(j,0,(1<<n)-1)
		{
			int s=~(i^j)&((1<<n)-1);
			int sum=0;
			REP(l,0,n-1)if(s>>l&1)sum+=w[l+1];
			if(sum<=100)ans[j][sum]+=all[i];
		}
	}
	REP(i,0,(1<<n)-1)REP(j,1,100)ans[i][j]+=ans[i][j-1];
	REP(i,1,q)
	{
		scanf("%s",str+1);
		int s=0;
		REP(j,1,strlen(str+1))s+=(str[j]-'0')<<j-1;
		int k=read();
		printf("%d\n",ans[s][k]);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
#endif
	init();
	return 0;
}