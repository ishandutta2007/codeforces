#include<cstdio>

int a[111111];

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		while(a[i]%2==0)a[i]/=2;
		while(a[i]%3==0)a[i]/=3;
	}
	for(i=1;i<n;i++)if(a[i]!=a[i-1])
	{
		puts("No");
		return 0;
	}
	puts("Yes");
}