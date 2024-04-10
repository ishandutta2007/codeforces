#include<cstdio>
#include<algorithm>

std::pair<long long,long long> a[222222];

int main()
{
	long long s,e;
    long long i,j,r,n,m,t,tot=1LL;
    scanf("%I64d%I64d",&n,&m);
    for(i=0;i<m;i++)
	{
        scanf("%I64d%I64d%I64d%I64d",&t,&s,&e,&r);
        e++;
        while(t++<n)
		{
			s<<=1LL;
			e<<=1LL;
		}
		if(r==1)tot++;
		a[i]=std::make_pair(s,r+1);
		a[i+m]=std::make_pair(e,-r-1);
	}
	a[m+m]=std::make_pair(1LL<<(n-1LL),2);
	a[m+m+1]=std::make_pair(1LL<<n,-2);
    std::sort(a,a+m+m+2);
    j=e=0;
    for(i=0;i<m+m+1LL;i++)
	{
		if(a[i].second==1)j++;
		if(a[i].second==2)tot--;
		if(a[i].second==-1)j--;
		if(a[i].second==-2)tot++;
		if(tot==0&&j==0&&a[i+1].first>a[i].first)
		{
			e+=a[i+1].first-a[i].first;
            s=a[i].first;
		}
	}
	if(e<=0)puts("Game cheated!");
	else if(e>1)puts("Data not sufficient!");
	else printf("%I64d\n",s);
}