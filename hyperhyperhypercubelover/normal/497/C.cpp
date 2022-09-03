#include<cstdio>
#include<algorithm>
#include<set>

std::pair<std::pair<int,int>,std::pair<int,int> > a[222222];
int b[111111];

std::set<std::pair<int,int> > S;
std::set<std::pair<int,int> >::iterator it;

int r[111111];

int main()
{
    int i,n,m;
    scanf("%d",&n);
    for(i=0;i<n;i++)
	{
        scanf("%d%d",&a[i].first.first,&a[i].second.first);
        a[i].first.second=1;
        a[i].second.first=-a[i].second.first;
        a[i].second.second=i;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a[i+n].first.first,&a[i+n].second.first,&b[i]);
        a[i+n].second.second=i;
	}
	std::sort(a,a+n+m);
    for(i=0;i<n+m;i++)
	{
		if(a[i].first.second)
		{
			it=S.lower_bound(std::make_pair(-a[i].second.first,0));
			if(it==S.end())
			{
				puts("NO");
				return 0;
			}
			r[a[i].second.second]=it->second+1;
            b[it->second]--;
            if(b[it->second]==0)S.erase(it);
		}
		else S.insert(a[i].second);
	}
	puts("YES");
	for(i=0;i<n;i++)printf("%d ",r[i]);
}