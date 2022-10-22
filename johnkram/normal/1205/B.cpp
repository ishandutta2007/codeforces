#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define MAXN 200005
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int n,i,j,k,s[60],d[205][205],ans;
ll a[MAXN];
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		for(j=0;j<60;j++)s[j]+=a[i]>>j&1;
	}
	sort(a+1,a+n+1,greater<ll>());
	for(;n>1&&!a[n];n--);
	for(i=0;i<60;i++)if(s[i]>=3)
	{
		puts("3");
		return 0;
	}
	memset(d,63,sizeof(d));
	ans=d[0][0];
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)if(a[i]&a[j])d[i][j]=1;
	for(i=1;i<=n;i++)d[i][i]=0;
	for(k=1;k<=n;k++)
	{
		for(i=1;i<k;i++)for(j=1;j<i;j++)if((a[i]&a[k])&&(a[k]&a[j]))ans=min(ans,d[i][j]+2);
		for(i=1;i<=n;i++)for(j=1;j<=n;j++)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	}
	if(ans==d[0][0])ans=-1;
	cout<<ans<<endl;
	return 0;
}