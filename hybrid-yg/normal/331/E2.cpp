#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
const int N=100005,E=262144;
int n,m,i,u,v,p,t,vis[55][55],j,k;
vector<int> g[55][55];
int q[N],l,r;
vector<int> ansr,ansl,w[55][55];
long long g1[55][55][105],g2[55][55][105],g3[55][55][105];
long long dp[105][55][2],f[55][55][105],ans[55][105],fe[55][55][105];
bool flag1=true;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
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
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
		if(i!=j)
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
				if(ansl.size()+ansr.size()<=2*n)
				{
					++g1[ansl[ansl.size()-1]][ansr[ansr.size()-1]][ansl.size()+ansr.size()-1];
				}
			}
		}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(g[i][j].size()&&g[i][j][0]==j)
			{
				l=1,r=0;
				for(p=1;p<g[i][j].size();++p)
					q[++r]=g[i][j][p];
				p=j;
				ansr.clear();
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
				++g3[i][ansr[ansr.size()-1]][ansr.size()];
			}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			if(g[i][j].size()&&g[i][j][g[i][j].size()-1]==i)
			{
				l=1,r=0;
				for(p=g[i][j].size()-2;p>=0;--p)
					q[++r]=g[i][j][p];
				p=i;
				ansl.clear();
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
				++g2[ansl[ansl.size()-1]][j][ansl.size()];
			}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=1;k<=2*n;++k)
				if(g1[i][j][k]||g2[i][j][k]||g3[i][j][k])
					w[i][j].push_back(k);
	for(i=1;i<=n;++i)
	{
		memset(dp,0,sizeof(dp));
		dp[0][i][0]=1;
		for(j=1;j<=n*2;++j)
			for(k=1;k<=n;++k)
				for(l=1;l<=n;++l)
					for(auto m:w[l][k])
					{
						dp[j][k][0]=(dp[j][k][0]+dp[j-m][l][0]*g2[l][k][m])%M;
						dp[j][k][1]=(dp[j][k][1]+dp[j-m][l][0]*g1[l][k][m]+dp[j-m][l][1]*g3[l][k][m])%M;
					}
		for(j=1;j<=n;++j)
			for(k=1;k<=2*n;++k)
				f[i][j][k]=dp[k][j][1];
	}
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(k=1;k<=2*n;++k)
				ans[j][k]=(ans[j][k]+f[i][j][k])%M;
	for(i=1;i<=n;++i)
		for(j=1;j<=n;++j)
			for(l=1;l<=n;++l)
				if(g[l][i].size()==0&&vis[l][i])
					for(k=1;k<2*n;++k)
						fe[l][j][k+1]=(fe[l][j][k+1]+f[i][j][k])%M;
	for(k=1;k<=2*n;++k)
		for(i=1;i<=n;++i)
			for(j=1;j<=n;++j)
				for(l=1;l<=k;++l)
					ans[i][k]=(ans[i][k]+ans[j][k-l]*fe[j][i][l])%M;
	for(k=1;k<=2*n;++k)
	{
		long long s=0;
		for(i=1;i<=n;++i)
			s=(s+ans[i][k])%M;
		cout<<s<<endl;
	}
}