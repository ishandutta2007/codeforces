#include<cstdio>
#include<vector>

std::vector<std::pair<int,std::pair<int,int> > > g[100001];
int d[100001];
int v[100001];
int n;

int c[100001];
double x[100001];
double r;

void f(int x)
{
	int i;
	v[x]=1;
    for(i=0;i<g[x].size();i++)if(!v[g[x][i].second.first])
	{
		f(g[x][i].second.first);
		d[x]+=d[g[x][i].second.first];
        r+=1.*g[x][i].second.second*(n-d[g[x][i].second.first])*(n-d[g[x][i].second.first]-1)*d[g[x][i].second.first];
        r+=1.*g[x][i].second.second*d[g[x][i].second.first]*(n-d[g[x][i].second.first])*(d[g[x][i].second.first]-1);
        ::x[g[x][i].first]=1.*(n-d[g[x][i].second.first])*(n-d[g[x][i].second.first]-1)*d[g[x][i].second.first]+1.*d[g[x][i].second.first]*(n-d[g[x][i].second.first])*(d[g[x][i].second.first]-1);
	}
	d[x]++;
}

int main()
{
	int a,b;
	int i,m;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c[i]);
        g[a].push_back(std::make_pair(i,std::make_pair(b,c[i])));
		g[b].push_back(std::make_pair(i,std::make_pair(a,c[i])));
	}
    f(1);
    r/=1.*n*(n-1)*(n-2)/6;
    scanf("%d",&m);
    while(m--)
	{
		scanf("%d%d",&a,&b);
        r-=x[a]*(c[a]-b)/(1.*n*(n-1)*(n-2)/6);
        c[a]=b;
        printf("%lf\n",r);
	}
}