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

#define int ll

int ans[100020],v[100020],t[100020];
int ans2[100020];

#undef int

int main()
#define int ll
{
#ifndef ONLINE_JUDGE
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
#endif
	int n=read();
	REP(i,1,n)v[i]=read();
	REP(i,1,n)t[i]=read()+t[i-1];
	t[n+1]=t[n];
	
	REP(i,1,n)
	{
		int l=i,r=n+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			if(t[mid]-t[i-1]>=v[i])r=mid;
			else l=mid+1;
		}
		ans[i]+=1;
		ans[l]--;
		ans2[l]+=v[i]-(t[l-1]-t[i-1]);
	}
	REP(i,1,n)ans[i]+=ans[i-1];
	REP(i,1,n)printf("%lld ",ans[i]*(t[i]-t[i-1])+ans2[i]);
	return 0;
}