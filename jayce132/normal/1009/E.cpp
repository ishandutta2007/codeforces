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

const int maxn=1e6+20;
const int mod=998244353;
int a[maxn],p2[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("E.in","r",stdin);
    freopen("E.out","w",stdout);
#endif
	int n=read();p2[0]=1;
	REP(i,1,n)a[i]=(a[i-1]+read())%mod,p2[i]=(ll)p2[i-1]*2%mod;
	int ans=0;
	REP(i,1,n-2)
	{
		ans=(ans+(ll)2*p2[n-i-1]*a[i]%mod+(ll)p2[n-i-2]*a[i]%mod*(n-i-1))%mod;
	}
	ans=(ans+(ll)2*a[n-1])%mod;ans=(ans+a[n])%mod;
	printf("%d\n",ans);
	return 0;
}