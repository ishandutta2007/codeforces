#include<bits/stdc++.h>
using namespace std;
int f[5005][5005],a[5005],n,m,i,j,k;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=j=1;i<=n;i++)
	{
		for(k=0;k<=m;k++)f[i][k]=f[i-1][k];
		for(;a[j]+5<a[i];j++);
		for(k=0;k<m;k++)f[i][k+1]=max(f[i][k+1],f[j-1][k]+i-j+1);
	}
	cout<<f[n][m]<<endl;
	return 0;
}