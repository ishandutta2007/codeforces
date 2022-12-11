#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
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

const int maxn=1e2+20;

int n,a[maxn],d;

void init()
{
	n=read();d=read();REP(i,1,n)a[i]=read();
	sort(a+1,a+n+1);
}

bool check(int x)
{
	int ans=a[n]-a[1];
	REP(i,0,x)
		ans=min(ans,a[n+i-x]-a[i+1]);
	return ans<=d;
}

void doing()
{
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	cout<<l<<endl;
}

int main()
{
	init();
	doing();
	return 0;
}