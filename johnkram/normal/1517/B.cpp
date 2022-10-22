#include<bits/stdc++.h>
using namespace std;
#define ll long long
int T,n,m,i,j,k,x,y,ans,a[105][105],b[105][105];
set<pair<int,pair<int,int>>> s,t[105];
void del(int x,int y)
{
	s.erase(make_pair(a[x][y],make_pair(x,y)));
	t[x].erase(make_pair(a[x][y],make_pair(x,y)));
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		s.clear();
		for(i=1;i<=n;i++)t[i].clear();
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)
		{
			scanf("%d",a[i]+j);
			s.insert(make_pair(a[i][j],make_pair(i,j)));
			t[i].insert(make_pair(a[i][j],make_pair(i,j)));
		}
		for(i=1;i<=m;i++)
		{
			x=s.begin()->second.first;
			y=s.begin()->second.second;
			del(x,y);
			b[x][i]=a[x][y];
			for(j=1;j<=n;j++)if(j!=x)
			{
				k=t[j].rbegin()->second.second;
				del(j,k);
				b[j][i]=a[j][k];
			}
		}
		for(i=1;i<=n;i++)for(j=1;j<=m;j++)printf("%d%c",b[i][j],j==m?'\n':' ');
	}
	return 0;
}