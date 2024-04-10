#include<cstdio>
#include<vector>
#include<queue>

std::vector<int> g[111111];
int v[111111];
int d[111111];

int main()
{
	std::priority_queue<std::pair<std::pair<double,int>,int> > pq;
	std::pair<std::pair<double,int>,int> p;
	double max=2;
    int maxi;
    int i,j,k,n,m,l;
    scanf("%d%d%d",&n,&m,&l);
	for(i=0;i<l;i++)
	{
		scanf("%d",&j);
		v[j]=i+1;
	}
	while(m--)
	{
		scanf("%d%d",&i,&j);
        g[i].push_back(j);
        g[j].push_back(i);
	}
    for(i=1;i<=n;i++)if(v[i])for(j=0;j<g[i].size();j++)d[g[i][j]]++;
    for(i=1;i<=n;i++)if(!v[i])pq.push(std::make_pair(std::make_pair(1.*d[i]/g[i].size(),l),i));
    for(i=l;i<n;i++)
	{
        do
		{
			p=pq.top();
			pq.pop();
		}while(v[p.second]);
		if(max>p.first.first)
		{
			max=p.first.first;
			maxi=i;
		}
        v[p.second]=i+1;
        for(j=0;j<g[p.second].size();j++)
		{
            d[g[p.second][j]]++;
			pq.push(std::make_pair(std::make_pair(1.*d[g[p.second][j]]/g[g[p.second][j]].size(),i+1),g[p.second][j]));
		}
	}
	printf("%d\n",n-maxi);
	for(i=1;i<=n;i++)if(v[i]>maxi)printf("%d ",i);
}