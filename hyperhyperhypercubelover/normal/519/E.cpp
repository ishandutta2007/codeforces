#include<cstdio>
#include<vector>

std::vector<int> g[111111];
int v[111111];
int p[22][111111];
int q[111111];

void dfs(int x)
{
    int i;
    q[x]=1;
    for(i=0;i<g[x].size();i++)if(!v[g[x][i]])
	{
		v[g[x][i]]=v[x]+1;
		dfs(g[x][i]);
        p[1][g[x][i]]=x;
        q[x]+=q[g[x][i]];
	}
}

int main()
{
	int dis,a,b;
    int i,j,k,n,m;
    scanf("%d",&n);
    for(i=1;i<n;i++)
	{
		scanf("%d%d",&j,&k);
		g[j].push_back(k);
		g[k].push_back(j);
	}
	v[1]=1;
    dfs(1);
    for(i=2;i<22;i++)for(j=1;j<=n;j++)p[i][j]=p[i-1][p[i-1][j]];
	scanf("%d",&m);
    while(m--)
	{
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			printf("%d\n",n);
			continue;
		}
		dis=0;
		j=a;
		k=b;
        for(i=21;i>0;i--)
		{
			if(v[j]>v[k]&&(((v[j]-v[k])>>(i-1))&1))
			{
				dis+=1<<(i-1);
                j=p[i][j];
			}
			if(v[k]>v[j]&&(((v[k]-v[j])>>(i-1))&1))
			{
				dis+=1<<(i-1);
                k=p[i][k];
			}
		}
        if(dis&1)
		{
			puts("0");
			continue;
		}
		for(i=21;i>0;i--)if(p[i][j]!=p[i][k])
		{
			dis+=1<<i;
            j=p[i][j];
            k=p[i][k];
		}
		if(v[a]==v[b])
		{
			printf("%d\n",n-q[j]-q[k]);
			continue;
		}
		if(j!=k)dis+=2;
        dis>>=1;
        dis--;
        if(v[a]>v[b])k=a;
        else k=b;
        for(i=21;i>0;i--)if((dis>>(i-1))&1)k=p[i][k];
        printf("%d\n",q[p[1][k]]-q[k]);
	}
	return 0;
}