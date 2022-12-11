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
#ifndef ONLINE_JUDGE
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
#endif
	int m=read(),n=read(),p[100];
	REP(i,1,n)
	{
		printf("1\n");fflush(stdout);int ans=read();
		if(ans==0)exit(0);
		else if(ans==1)p[i]=-1;
		else p[i]=1;
	}
	int l=1,r=m,cs=0;
	while(l<r)
	{
		++cs;
		if(cs==n+1)cs=1;
		int mid=(l+r)>>1;
		printf("%d\n",mid);fflush(stdout);int ans=read();
		if(ans==0)exit(0);
		else {
			ans*=p[cs];
			if(ans==1)r=mid-1;
			else l=mid+1;
		}
	}
	printf("%d\n",l);fflush(stdout);int ans=read();
	exit(0);
	return 0;
}