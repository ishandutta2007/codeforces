#include<cstdio>
#include<algorithm>

int a[222222];
std::pair<int,int> d[222222];

int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
        d[i].first=a[i]+i;
        d[i].second=i;
	}
    std::sort(d,d+n);
    for(i=1;i<n;i++)if(d[i].first==d[i-1].first)
	{
		puts(":(");
		return 0;
	}
    for(i=0;i<n;i++)printf("%d ",a[d[i].second]-i+d[i].second);
}