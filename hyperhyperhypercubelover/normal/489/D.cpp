#include<cstdio>
#include<algorithm>

std::pair<int,int> d[30000];
int v[3][3001];

int main()
{
	long long r=0;
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)scanf("%d%d",&d[i].first,&d[i].second);
    for(i=1;i<=n;i++)
	{
		for(j=0;j<=2;j++)for(k=1;k<=n;k++)v[j][k]=0;
		v[0][i]=1;
		for(j=1;j<=2;j++)for(k=0;k<m;k++)v[j][d[k].second]+=v[j-1][d[k].first];
		for(k=1;k<=n;k++)if(k!=i)r+=v[2][k]*(v[2][k]-1)/2;
	}
	printf("%I64d",r);
}