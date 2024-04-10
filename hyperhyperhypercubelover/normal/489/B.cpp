#include<cstdio>
#include<algorithm>

int a[100];
int b[100];
int v[100];

int main()
{
	int i,j,n,m,r=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)scanf("%d",&b[i]);
	std::sort(a,a+n);
	std::sort(b,b+m);
    for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)if(a[i]-b[j]<=1&&a[i]-b[j]>=-1&&!v[j])break;
		if(j<m)
		{
			v[j]=1;
			r++;
		}
	}
	printf("%d",r);
}