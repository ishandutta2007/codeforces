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

const int maxn=1e5+20;

int k[maxn],b[maxn],n,m;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
#endif
	n=read();m=read();
	ll all=0;
	REP(i,1,m)
	{
		int x=read(),d=read();
		all+=x*n;
		if(d>0)all+=(ll)n*(n-1)*d/2;
		else {
			int mid=(n+1)>>1;
			all+=(ll)mid*(mid-1)*d/2+(ll)(n-mid)*(n-mid+1)*d/2;
		}
	}
	printf("%.8lf\n",all/n+(double)(all%n)/n);
	return 0;
}