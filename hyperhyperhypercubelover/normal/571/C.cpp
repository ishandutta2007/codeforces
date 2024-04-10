#include<cstdio>
#include<algorithm>
#include<queue>

std::vector<int> a[222222];
std::vector<int> b[222222];
int d[222222];
int v[222222];
int r[222222];

int main()
{
	std::priority_queue<std::pair<int,int> > PQ;
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		d[i]=j;
		while(j--)
		{
			scanf("%d",&k);
			a[i].push_back(k);
            b[std::abs(k)].push_back(i);
		}
	}
	for(i=0;i<n;i++)PQ.push(std::make_pair(-d[i],i));
	while(!PQ.empty())
	{
		std::pair<int,int> p=PQ.top();
		PQ.pop();
		if(v[p.second])continue;
		for(i=0;i<a[p.second].size();i++)if(r[std::abs(a[p.second][i])]&&r[std::abs(a[p.second][i])]*a[p.second][i]>0)break;
        if(i<a[p.second].size())continue;
        if(p.first==0)
		{
			puts("NO");
			return 0;
		}
        for(i=0;i<a[p.second].size();i++)if(!r[std::abs(a[p.second][i])])break;
        k=a[p.second][i];
        r[std::abs(k)]=k/std::abs(k);
        for(i=0;i<b[std::abs(k)].size();i++)if(b[std::abs(k)][i]!=p.second)
		{
			d[b[std::abs(k)][i]]--;
            PQ.push(std::make_pair(-d[b[std::abs(k)][i]],b[std::abs(k)][i]));
		}
	}
	puts("YES");
	for(i=1;i<=m;i++)putchar(r[i]>0?'1':'0');
}