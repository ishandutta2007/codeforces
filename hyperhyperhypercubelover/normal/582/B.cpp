#include<cstdio>
#include<algorithm>

int a[11111];
int c[333];
int d[11111];

int L[11111];
int R[11111];

int main()
{
	int i,j,n,m,r=0;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]++;
	}
	if(m<111)
	{
        for(j=n;j<n*m;j++)a[j]=a[j-n];
        for(i=0;i<n*m;i++)
		{
            d[i+1]=1111;
            *std::upper_bound(d,d+i+1,a[i])=a[i];
		}
		printf("%d",std::lower_bound(d,d+n*m+1,1111)-d-1);
		return 0;
	}
	for(j=n;j<n*111;j++)a[j]=a[j-n];
    for(i=0;i<n*111;i++)
	{
		d[i+1]=1111;
        L[i]=std::upper_bound(d,d+i+1,a[i])-d;
		*std::upper_bound(d,d+i+1,a[i])=a[i];
	}
	d[0]=-1111;
    for(i=0;i<n*111;i++)
	{
        d[i+1]=1111;
        R[n*111-i-1]=std::upper_bound(d,d+i+1,-a[n*111-i-1])-d;
		*std::upper_bound(d,d+i+1,-a[n*111-i-1])=-a[n*111-i-1];
	}
	for(i=0;i<n*111;i++)r=std::max(r,L[i]+R[i]+c[a[i]]*(m-111));
	printf("%d",r-1);
    return 0;
}