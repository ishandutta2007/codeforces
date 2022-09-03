#include<cstdio>
#include<algorithm>

std::pair<int,int> a[111111];

int main()
{
    int i,n,m,max=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++)scanf("%d%d",&a[i].first,&a[i].second);
	max=std::max(a[0].second+a[0].first-1,a[m-1].second-a[m-1].first+n);
	for(i=1;i<m;i++)
	{
		if(std::abs(a[i].second-a[i-1].second)>a[i].first-a[i-1].first)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
        max=std::max(max,std::max(a[i].second,a[i-1].second)+(a[i].first-a[i-1].first-std::abs(a[i].second-a[i-1].second))/2);
	}
	printf("%d",max);
}