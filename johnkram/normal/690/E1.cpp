#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
int a[605][605],A[605],S,t,n,m,i,j;
double X,Y;
inline int ABS(int x)
{
	if(x<0)return -x;
	return x;
}
double get(int x,int y)
{
	int i;
	for(i=1;i<=m;i++)A[i]=ABS(a[x][i]-a[y][i]);
	sort(A+1,A+m+1);
	for(i=max(m/10,1),S=0;i<=m*9/10;i++)S+=A[i];
	return (double)S/(m*9/10-max(m/10,1)+1);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)scanf("%d",a[i]+j);
		X=get(1,n);
		Y=get(n+1>>1,n+3>>1);
		if(X/Y<1)puts("YES");
		else puts("NO");
	}
	return 0;
}