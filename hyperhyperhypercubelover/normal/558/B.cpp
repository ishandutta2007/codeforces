#include<cstdio>
#include<algorithm>

int c[1111111];
int l[1111111];
int r[1111111];

int main()
{
	int i,n,t;
	for(i=0;i<1111111;i++)l[i]=1e9;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
        c[t]++;
        l[t]=std::min(l[t],i);
        r[t]=std::max(r[t],i);
	}
	t=0;
    for(i=0;i<1111111;i++)
	{
		if(c[i]>c[t])t=i;
        else if(c[i]==c[t]&&r[i]-l[i]<r[t]-l[t])t=i;
	}
    printf("%d %d\n",l[t],r[t]);
}