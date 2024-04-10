#include<cstdio>
#include<vector>
#include<queue>

std::vector<std::pair<int,int> > g[333333];
std::vector<int> t[333333];
long long d[333333];
int r[333333],rn;

int main()
{
	std::pair<long long,int> p;
	std::priority_queue<std::pair<long long,int> > pq;
	long long res=0;
	int i,j,k,n,m,tt;
	scanf("%d%d",&n,&m);
	for(tt=1;tt<=m;tt++)
	{
		scanf("%d%d%d",&i,&j,&k);
		g[i].push_back(std::make_pair(j,k));
		g[j].push_back(std::make_pair(i,k));
		t[i].push_back(tt);
		t[j].push_back(tt);
	}
	scanf("%d",&i);
	pq.push(std::make_pair(-1LL,i));
	while(!pq.empty())
	{
		p = pq.top();
		pq.pop();
        if(d[p.second])continue;
        d[p.second]=-p.first;
        for(i=0;i<g[p.second].size();i++)pq.push(std::make_pair(p.first-g[p.second][i].second,g[p.second][i].first));
	}
	for(i=1;i<=n;i++)if(d[i]!=1)
	{
		for(k=0;k<g[i].size();k++)if(d[i]-d[g[i][k].first]==g[i][k].second)break;
        for(j=k+1;j<g[i].size();j++)if(d[i]-d[g[i][j].first]==g[i][j].second&&g[i][j].second<g[i][k].second)k=j;
		res+=g[i][k].second;
		r[rn++]=t[i][k];
	}
	printf("%I64d\n",res);
	for(i=0;i<rn;i++)printf("%d ",r[i]);
}