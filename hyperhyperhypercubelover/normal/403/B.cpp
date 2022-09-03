#include<cstdio>
#include<algorithm>

int a[5000];
int b[5000];
int d[5000];
int m;

int f(int x)
{
	int i,r=0;
    for(i=2;i*i<=x;i++)while(x%i==0)
	{
		x/=i;
        if(std::binary_search(b,b+m,i))r--;
        else r++;
	}
	if(x>1)
	{
        if(std::binary_search(b,b+m,x))r--;
        else r++;
	}
	return r;
}

int g(int x,int y){return x?g(y%x,x):y;}

int main()
{
	int i,j,k,n;
	scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		if(i==0)d[i]=a[i];
		else d[i]=g(d[i-1],a[i]);
	}
    for(i=0;i<m;i++)scanf("%d",&b[i]);
    std::sort(b,b+m);
    j=1;
    for(i=n-1;i>=0;i--)
	{
		if(f(d[i]/j)<0)j=d[i];
		a[i]/=j;
	}
	k=0;
	for(j=0;j<n;j++)k+=f(a[j]);
	printf("%d",k);
}