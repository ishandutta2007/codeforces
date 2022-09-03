#include<cstdio>
#include<vector>

std::vector<int> g[3333];
int d[3333][3333];
int Q[3333],qn;

int main()
{
	int res;
	int p,q,r,s,t,u;
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	for(k=0;k<m;k++)
	{
		scanf("%d%d",&i,&j);
		g[i].push_back(j);
		g[j].push_back(i);
	}
	scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u);

	for(i=1;i<=n;i++)
	{
		qn=0;
		d[i][i]=1;
		Q[qn++]=i;
		for(j=0;j<qn;j++)for(k=0;k<g[Q[j]].size();k++)if(!d[i][g[Q[j]][k]])
		{
            d[i][g[Q[j]][k]]=d[i][Q[j]]+1;
            Q[qn++]=g[Q[j]][k];
		}
	}

	for(i=1;i<=n;i++)for(j=1;j<=n;j++)d[i][j]--;

	if(d[p][q]>r||d[s][t]>u)
	{
		puts("-1");
		return 0;
	}

	res=d[p][q]+d[s][t];
	for(i=1;i<=n;i++)for(j=1;j<=n;j++)
	{
		if(d[p][i]+d[i][j]+d[j][q]<=r&&d[s][i]+d[i][j]+d[j][t]<=u)
			res=std::min(res,d[p][i]+d[s][i]+d[i][j]+d[j][q]+d[j][t]);
		if(d[p][i]+d[i][j]+d[j][q]<=r&&d[t][i]+d[i][j]+d[j][s]<=u)
			res=std::min(res,d[p][i]+d[t][i]+d[i][j]+d[j][q]+d[j][s]);
	}
	printf("%d",m-res);
}