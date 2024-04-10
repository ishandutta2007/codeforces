#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 100005
int n,m,a[MAXN],i,j;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=2,j=1;i<=n;i++)if(a[i]-a[i-1]<=m)j++;
	else j=1;
	cout<<j<<endl;
	return 0;
}