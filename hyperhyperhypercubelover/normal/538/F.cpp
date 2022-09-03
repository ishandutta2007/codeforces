#include<cstdio>
#include<algorithm>

std::pair<int,int> a[222222];
int r[222222];

int T[222222];

void add(int x)
{
	while(x<222222)
	{
		T[x]++;
		x+=x&-x;
	}
}

int get(int x)
{
	int r=0;
    while(x)
	{
		r+=T[x];
		x-=x&-x;
	}
	return r;
}

int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
	}
    std::sort(a+1,a+n+1);
    for(i=1;i<=n;i++)
	{
        for(j=1;j<n&&j*(a[i].second-1)+2<=n;j++)r[j]+=get(std::min(j*a[i].second+1,n))-get(j*(a[i].second-1)+1);
        add(a[i].second);
	}
	for(i=1;i<n;i++)printf("%d ",r[i]);
}