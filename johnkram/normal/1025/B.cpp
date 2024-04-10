#include<bits/stdc++.h>
using namespace std;
int a[150005],b[150005],p[1005],n,m,i,j;
void ask(int x)
{
	for(i=2;i*i<=x;i++)if(x%i==0)for(p[m++]=i;x%i==0;x/=i);
	if(x>1)p[m++]=x;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	ask(a[1]);
	ask(b[1]);
	sort(p,p+m);
	m=unique(p,p+m)-p;
	for(i=0;i<m;i++)
	{
		for(j=1;j<=n;j++)if(a[j]%p[i]&&b[j]%p[i])break;
		if(j>n)
		{
			cout<<p[i]<<endl;
			return 0;
		}
	}
	puts("-1");
	return 0;
}