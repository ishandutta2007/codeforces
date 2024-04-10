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

int n,m,a[1020],b[1020];


inline bool check(double x)
{
	REP(i,1,n)
	{
		double cost=(x+m)/a[i];
		x-=cost;
		if(x<0)return 0;
		cost=(x+m)/b[i+1];
		x-=cost;
		if(x<0)return 0;
	}
	return 1;
}

int main()
{
	n=read();m=read();
	REP(i,1,n)a[i]=read();
	REP(i,1,n)b[i]=read();b[n+1]=b[1];
	//REP(i,1,n)if(a[i]<=1)puts("-1"),exit(0);
	//REP(i,1,n)if(b[i]<=1)puts("-1"),exit(0);
	double l=0,r=2e9;
	while(l+1e-7<r)
	{
		double mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(l>1e9+1)puts("-1");
	else printf("%.10lf\n",l);
	return 0;
}