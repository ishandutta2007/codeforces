#include<cstdio>
#include<vector>
#include<algorithm>

std::pair<int,int> M[15000000];
std::vector<int> t[100001];
std::vector<std::pair<int,int> > g[100001];
int d[335],dn;
int r[335][100001];
int q[1000],qn;
int v[100001];
int Mn;

int root(int x,int y){return y==r[x][y]?y:(r[x][y]=root(x,r[x][y]));}
void comb(int x,int y,int z){r[x][root(x,y)]=root(x,z);}

void dfs(int x,int y)
{
	if(v[x])return;
	int i;
	v[x]=y;
	for(i=0;i<t[x].size();i++)dfs(t[x][i],y);
}

int main()
{
	int a,b,c;
	int i,j,k,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
        g[c].push_back(std::make_pair(a,b));
	}
	for(i=1;i<=m;i++)
	{
		if(g[i].size()>300)
		{
			d[++dn]=i;
			for(j=1;j<=n;j++)r[dn][j]=j;
			for(j=0;j<g[i].size();j++)comb(dn,g[i][j].first,g[i][j].second);
		}
		else
		{
			qn=0;
			for(j=0;j<g[i].size();j++)
			{
				q[++qn]=g[i][j].first;
				q[++qn]=g[i][j].second;
				t[g[i][j].first].push_back(g[i][j].second);
				t[g[i][j].second].push_back(g[i][j].first);
			}
			std::sort(q+1,q+qn+1);
            qn=std::unique(q+1,q+qn+1)-q-1;
			for(j=1;j<=qn;j++)v[q[j]]=0;
			for(j=1;j<=qn;j++)dfs(q[j],j);
			for(j=1;j<=qn;j++)for(k=1;k<=qn;k++)if(q[j]<q[k]&&v[q[j]]==v[q[k]])M[Mn++]=std::make_pair(q[j],q[k]);
			for(j=1;j<=qn;j++)t[q[j]].clear();
		}
	}
	std::sort(M,M+Mn);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		if(a>b)a^=b^=a^=b;
		k=std::upper_bound(M,M+Mn,std::make_pair(a,b))-std::lower_bound(M,M+Mn,std::make_pair(a,b));
        for(j=1;j<=dn;j++)if(root(j,a)==root(j,b))k++;
        printf("%d\n",k);
	}
}