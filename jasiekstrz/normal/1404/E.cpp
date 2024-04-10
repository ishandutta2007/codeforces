/*
 *    0
 *  3 + 1
 *    2
 */
#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
vector<int> e[100010];
pair<int,int> dd[4]={{-1,0},{0,1},{1,0},{0,-1}};
char tab[210][210];
int mtch[100010];
bool vis[100010];
inline int id(int i,int j,int m,int d)
{
	int x=(i-1)*m+j;
	int r=x+(i-1)*(m-1);
	if(d==0)
		return r-m;
	if(d==1)
		return r;
	if(d==2)
		return r+m-1;
	return r-1;
}
inline bool valid(int i,int j,int n,int m)
{
	if((i<1)||(n<i)||(j<1)||(m<j))
		return false;
	return (tab[i][j]=='#');
}
bool dfs(int x)
{
	vis[x]=true;
	for(auto v:e[x])
	{
		if(mtch[v]==0)
		{
			mtch[x]=v;
			mtch[v]=x;
			return true;
		}
		if((!vis[mtch[v]])&&dfs(mtch[v]))
		{
			mtch[v]=x;
			mtch[x]=v;
			return true;
		}
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,ans=0,i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>tab[i][j];
			ans+=(tab[i][j]=='#');
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!valid(i,j,n,m))
				continue;
			for(int k:{0,1,2,3})
			{
				int x=i+dd[k].fi;
				int y=j+dd[k].se;
				int a=i+dd[(k+1)%4].fi;
				int b=j+dd[(k+1)%4].se;
				if(valid(x,y,n,m)&&valid(a,b,n,m))
				{
					e[id(i,j,m,k)].push_back(id(i,j,m,(k+1)%4));
					e[id(i,j,m,(k+1)%4)].push_back(id(i,j,m,k));
				}
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(!valid(i,j,n,m))
				continue;
			if(valid(i+1,j,n,m))
				ans--;
			if(valid(i,j+1,n,m))
				ans--;
		}
	}
	int k=n*m+(n-1)*(m-1)-1;
	while(true)
	{
		bool ok=false;
		for(i=1;i<=k;i++)
			vis[i]=false;
		for(i=1;i<=k;i++)
		{
			if((!vis[i])&&(mtch[i]==0)&&dfs(i))
			{
				ok=true;
				ans++;
			}
		}
		if(!ok)
			break;
	}
	cout<<ans<<"\n";
	return 0;
}