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
	ll n=read(),m=read(),k=read();
	ll N=n,M=m;
	ll dn=__gcd(n,k);
	n/=dn; k/=dn;
	ll dm=__gcd(m,k);
	m/=dm; k/=dm;
	int p2=0;
	if(k>2)puts("NO"),exit(0);
	k=3-k;
	if(N*M<n*m*k)puts("NO"),exit(0);
	if(k==1)printf("YES\n0 0\n%lld 0\n0 %lld\n",n,m);
	else
	{
		if(n*2<=N)printf("YES\n0 0\n%lld 0\n0 %lld\n",n*2,m);
		else if(m*2<=M)printf("YES\n0 0\n%lld 0\n0 %lld\n",n,m*2);
		else puts("NO");
	}
	return 0;
}