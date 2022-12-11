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

const int maxn=2e5+20;

char str[maxn];

int f[maxn],g[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
#endif
	scanf("%s",str+1);str[0]='0';
	int n=strlen(str+1);
	REP(i,1,n)str[i+n]=str[i];
	int ans=0;
	REP(i,1,2*n)
	{
		if(str[i]!=str[i-1])f[i]=f[i-1]+1;
		else f[i]=1;
		if(ans<f[i])ans=f[i];
	}
	printf("%d\n",min(ans,n));
	return 0;
}