#include<cstdio>

int a[100000];

int main()
{
	int l,r;
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
    l=r=i=0;
    j=n-1;
    while(i<=j)
	{
        if(l>r)r+=a[j--];
        else l+=a[i++];
	}
	printf("%d %d",i,n-i);
}