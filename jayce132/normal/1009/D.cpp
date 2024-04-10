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

int n,m;
const int maxn=1e5+20;
int l[maxn],r[maxn],tot;

inline void doing()
{
	n=read();m=read();
	if(m<n-1){puts("Impossible");exit(0);}
	REP(i,1,n-1)l[i]=i,r[i]=i+1;tot=n-1;
	REP(i,1,n-2)
	{
		REP(j,i+2,n)
		{
			if(tot>=m)break;
			if(__gcd(i,j)==1)l[++tot]=i,r[tot]=j;
			if(tot>=m)break;
		}
		if(tot>=m)break;
	}
	if(tot<m){puts("Impossible");exit(0);}
	puts("Possible");
	REP(i,1,m)printf("%d %d\n",l[i],r[i]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
#endif
	doing();
	return 0;
}