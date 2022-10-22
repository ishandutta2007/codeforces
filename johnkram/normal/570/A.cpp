#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int a[105][105],n,m,i,j,k,b[105];
int main()
{
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",a[i]+j);
	for(i=1;i<=n;i++,b[k]++)for(j=k=1;j<=m;j++)if(a[i][j]>a[i][k])k=j;
	for(i=j=1;i<=m;i++)if(b[i]>b[j])j=i;
	printf("%d\n",j);
	return 0;
}