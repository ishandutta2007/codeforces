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

int main()
{
	int n=read(),m=read(),a[10020],b[10020];
	REP(i,1,n)a[i]=read();
	REP(i,1,m)b[i]=read();
	int j=1,ans=0;
	REP(i,1,n)
	{
		if(j<=m && a[i]<=b[j])
		{
			ans++;
			j++;
		}
	}
	printf("%d\n",ans);
	return 0;
}