#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

vector<int> qq;
vector<int> point[105],key[105];
int co[105],v[105],v1[105],v2[105],ok;

void dfs1(int i)
{
	v1[i]=1;
	for (int p=0;p<(int)point[i].size();p++)
	{
		int j=point[i][p];
		int k=key[i][p];
		if (!v1[j])
		{
			co[j]=k^co[i];
			dfs1(j);
		}
		else
		{
			if ((co[i]^co[j])!=k) ok=0;
		}
	}
}

void dfs2(int i)
{
	v2[i]=1;
	for (int p=0;p<(int)point[i].size();p++)
	{
		int j=point[i][p];
		int k=key[i][p];
		if (!v2[j])
		{
			co[j]=k^co[i];
			dfs2(j);
		}
		else
		{
			if ((co[i]^co[j])!=k) ok=0;
		}
	}
}

void dfs(int i)
{
	v[i]=1;
	for (int p=0;p<(int)point[i].size();p++)
	{
		int j=point[i][p];
		if (!v[j])
		{
			dfs1(j);
		}
	}
}

int main()
{
	#ifdef LOCAL_TEST
		freopen("e.in","r",stdin);
		freopen("e.out","w",stdout);
	#endif
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		point[a].push_back(b);
		point[b].push_back(a);
		key[a].push_back(1-c);
		key[b].push_back(1-c);
	}
	int fuck=1;
	for (int i=1;i<=n;i++) if (!v[i])
	{
		ok=1;
		co[i]=0;
		dfs1(i);
		if (!ok)
		{
			ok=1;
			co[i]=1;
			dfs2(i);
			if (!ok)
			{
				fuck=0;
			}
		}
		dfs(i);
	}
	if (fuck==0) cout<<"Impossible"<<endl;
	else
	{
		for (int i=1;i<=n;i++) if (co[i]==1) qq.push_back(i);
		cout<<qq.size()<<endl;
		for (int i=0;i<(int)qq.size();i++) cout<<qq[i]<<" ";
		cout<<endl;
	}
	return 0;
}