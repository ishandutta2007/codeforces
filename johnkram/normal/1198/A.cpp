#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
int n,m,N,i,j,k,ans,a[MAXN],b[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	m<<=3;
	m/=n;
	if(m>=20)
	{
		puts("0");
		return 0;
	}
	m=1<<m;
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=k=1;i<=n;i=j,k++)
	{
		for(j=i;j<=n&&a[i]==a[j];j++);
		b[k]=j-i;
		N=k;
	}
	if(N<=m)
	{
		puts("0");
		return 0;
	}
	for(i=1;i<=N;i++)b[i]+=b[i-1];
	for(i=0;i+m<=N;i++)ans=max(ans,b[i+m]-b[i]);
	cout<<n-ans<<endl;
	return 0;
}