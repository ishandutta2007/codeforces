#include<bits/stdc++.h>
using namespace std;
int n,m,ans[30],i,j;
int main()
{
	scanf("%d",&n);
	for(i=2;i<26;i++)
	{
		m=(1<<i)-1;
		for(j=2;j*j<=m;j++)if(m%j==0)break;
		if(j*j>m)ans[i]=1;
		else ans[i]=m/j;
	}
	while(n--)
	{
		scanf("%d",&m);
		for(i=2;i<26;i++)if((1<<i)>m)break;
		if(m==(1<<i)-1)printf("%d\n",ans[i]);
		else printf("%d\n",(1<<i)-1);
	}
	return 0;
}