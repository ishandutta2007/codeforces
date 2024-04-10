#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,k;
int gcd(int x,int y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1,j=m;i<=n;i++)
	{
		scanf("%d",&k);
		j=gcd(j,k);
	}
	printf("%d\n",m/j);
	for(i=0;i<m;i+=j)printf("%d ",i);
	return 0;
}