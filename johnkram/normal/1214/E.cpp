#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define MAXN 1000005
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int n,m,i,a[MAXN],p[MAXN],f[MAXN];
bool cmp(int x,int y)
{
	if(a[x]==a[y])return x<y;
	return a[x]>a[y];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=1;i<=n;i++)p[i]=i;
	sort(p+1,p+n+1,cmp);
	m=n;
	for(i=1;i<=n;i++)f[i]=p[i]*2-1;
	for(i=1;i<=n;i++)if(i+a[p[i]]>m)f[++m]=p[i]*2;
	else printf("%d %d\n",p[i]*2,f[i+a[p[i]]-1]);
	for(i=1;i<m;i++)printf("%d %d\n",f[i],f[i+1]);
	return 0;
}