#include<cstdio>
#include<algorithm>

int a[3000];

int main()
{
    int i,j,k,n,t;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
	printf("%d\n",n);
	for(i=0;i<n;i++)
	{
		k=i;
		for(j=i;j<n;j++)if(a[j]<a[k])k=j;
        printf("%d %d\n",i,k);
		t=a[i];
		a[i]=a[k];
		a[k]=t;
	}
}