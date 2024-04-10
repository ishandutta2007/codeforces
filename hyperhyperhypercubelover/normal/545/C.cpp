#include<cstdio>

int a[111111];
int b[111111];

int main()
{
	int i,n,t=-1e9,r=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);
	a[n]=2.1e9;
	for(i=0;i<n;i++)
	{
		if(a[i]-b[i]>t)
		{
			r++;
			t=a[i];
		}
		else if(a[i]+b[i]<a[i+1])
		{
			r++;
			t=a[i]+b[i];
		}
		else t=a[i];
	}
	printf("%d",r);
}