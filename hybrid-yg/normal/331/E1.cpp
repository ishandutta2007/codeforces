#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=100005,E=262144;
int n,m,i,u,v,p,t,vis[55][55],j,k;
vector<int> g[55][55];
int q[N],l,r;
vector<int> ansr,ansl;
long long dp[105][55][2];
bool flag1=true;
int main()
{
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d %d",&u,&v);
		vis[u][v]=1;
		scanf("%d",&t);
		if(t==0)
			flag1=false;
		while(t--)
		{
			scanf("%d",&p);
			g[u][v].push_back(p);
		}
	}
	bool flag=true;
	for(i=1;i<=n&&flag;++i)
		for(j=1;j<=n&&flag;++j)
		{
			for(k=0;k+1<g[i][j].size();++k)
				if(g[i][j][k]==i&&g[i][j][k+1]==j)
					break;
			if(k+1<g[i][j].size())
			{
				l=1,r=0;
				for(p=k+2;p<g[i][j].size();++p)
					q[++r]=g[i][j][p];
				p=j;
				ansl.clear(),ansr.clear();
				ansr.push_back(j);
				while(l<=r&&r<=2*n)
				{
					if(!vis[p][q[l]])
						break;
					for(auto it:g[p][q[l]])
						q[++r]=it;
					p=q[l];
					ansr.push_back(q[l]);
					++l;
				}
				if(l<=r)
					continue;
				l=1,r=0;
				for(p=k-1;p>=0;--p)
					q[++r]=g[i][j][p];
				p=i;
				ansl.push_back(i);
				while(l<=r&&r<=2*n)
				{
					if(!vis[q[l]][p])
						break;
					for(int i=g[q[l]][p].size()-1;i>=0;--i)
						q[++r]=g[q[l]][p][i];
					p=q[l];
					ansl.push_back(q[l]);
					++l;
				}
				if(l<=r)
					continue;
				if(flag&&ansl.size()+ansr.size()<=2*n)
				{
					printf("%d\n",ansl.size()+ansr.size());
					for(j=ansl.size()-1;j>=0;--j)
						printf("%d ",ansl[j]);
					for(j=0;j<ansr.size();++j)
						printf("%d ",ansr[j]);
					flag=false;
				}
			}
		}
	if(flag)
		puts("0");
}