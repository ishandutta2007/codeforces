#include<cstdio>

int main()
{
    int i,n,a,b,c,r=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		if(a+b+c>1)r++;
	}
	printf("%d",r);
}