#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MN 1000000
#define MOD 1000000007
ll s[MN+5];int f[MN+5],p[MN+5],F[MN+5];
inline void rw(int&x,int y){if((x+=y)>=MOD)x-=MOD;}
int main()
{
	int n,i,j,ans=0;
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%lld",&s[i]);
	for(i=2;i<=n;++i)scanf("%d",&p[i]);
	for(i=n;i>1;--i)s[p[i]]+=s[i];
	for(i=n;i;--i)if((s[i]=s[1]/__gcd(s[1],s[i]))<=n)++f[s[i]];
	for(i=n;i;--i)for(j=i;(j+=i)<=n;)f[j]+=f[i];
	for(F[1]=i=1;i<=n;++i)if(f[i]==i)for(rw(ans,F[j=i]);(j+=i)<=n;)rw(F[j],F[i]);
	printf("%d",ans);
}