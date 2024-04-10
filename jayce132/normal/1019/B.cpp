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

inline int ask(int x)
{
	//fflush(stdout);
	printf("? %d\n",x);
	fflush(stdout);
	int y=read();
	return y;
}

inline void OUT(int x)
{
	printf("! %d\n",x);
	fflush(stdout);
	exit(0);
}

int main()
{
	int n=read();
	if(n/2%2==1)OUT(-1);
	int a=ask(1),b=ask(n/2+1),c=ask(n/2),d=ask(n);
	if(a==b)OUT(1);
	if(c==d)OUT(n/2);
	int l=1,r=n/2;
	while(l<r)
	{
		int mid=(l+r)>>1,A=ask(mid),B=ask(mid+n/2);
		if(A==B)OUT(mid);
		if((a>b && A>B) || (a<b && A<B))l=mid+1;
		else r=mid;
	}
	OUT(l);
	
	
	return 0;
}