#include<bits/stdc++.h>
using namespace std;
int mdlav;
vector<int> tab[510];
bool odw[510][510];
int v(int x,int y)
{
	return (x-1)*mdlav+y;
}
void DFS(int typ,int x)
{
	int d,i;
	odw[typ][x]=true;
	d=tab[x].size();
	for(i=0;i<d;i++)
	{
		if(!odw[typ][tab[x][i]])
			DFS(typ,tab[x][i]);
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m,i,j;
	char t;
	cin>>n>>m;
	mdlav=m;
	for(i=1;i<=n;i++)
	{
		cin>>t;
		for(j=1;j<m;j++)
		{
			if(t=='>')
				tab[v(i,j)].push_back(v(i,j+1));
			else
				tab[v(i,j+1)].push_back(v(i,j));
		}
	}
	for(j=1;j<=m;j++)
	{
		cin>>t;
		for(i=1;i<n;i++)
		{
			if(t=='^')
				tab[v(i+1,j)].push_back(v(i,j));
			else
				tab[v(i,j)].push_back(v(i+1,j));
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
			DFS(v(i,j),v(i,j));
	}
	for(i=1;i<=n*m;i++)
	{
		for(j=1;j<=n*m;j++)
		{
			if(!odw[i][j])
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}