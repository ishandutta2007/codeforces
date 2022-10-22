#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll N,n,a[MAXN];
int m,i,j,ans;
int main()
{
	scanf("%I64d%d%I64d",&N,&m,&n);
	for(i=1;i<=m;i++)scanf("%I64d",a+i);
	for(i=1;i<=m;i=j,ans++)for(j=i;j<=m&&(a[i]-i)/n==(a[j]-i)/n;j++);
	cout<<ans<<endl;
	return 0;
}