#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,i,j,a,b,p[1000005];
int main()
{
	cin>>n>>a>>b;
	for(m=0;m*a<=n;m++)if((n-m*a)%b==0)break;
	if(m*a>n)
	{
		puts("-1");
		return 0;
	}
	for(i=1;i<=n;i++)p[i]=i;
	for(i=1;m--;i+=a)
	{
		for(j=i;j+1<i+a;j++)p[j]=p[j+1];
		p[j]=i;
	}
	for(;i<=n;i+=b)
	{
		for(j=i;j+1<i+b;j++)p[j]=p[j+1];
		p[j]=i;
	}
	for(i=1;i<=n;i++)printf("%d ",p[i]);
	return 0;
}