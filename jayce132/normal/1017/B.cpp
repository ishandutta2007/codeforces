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
	const int maxn=1e5+20;
	int n,a[maxn],b[maxn],s[4]={0};
	n=read();REP(i,1,n)a[i]=getchar()-'0';getchar();
	REP(i,1,n)b[i]=getchar()-'0';
	REP(i,1,n)
	{
		s[a[i]+b[i]*2]++;
	}
	ll ans=0;
	ans+=(ll)s[0]*s[1];
	ans+=(ll)s[0]*s[3];
	ans+=(ll)s[1]*s[2];
	//ans+=(ll)s[1]*s[3];
	cout<<ans<<endl;
	return 0;
}