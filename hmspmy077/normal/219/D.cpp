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

const int N=200005;

int v[N],pp,ans;
vector<int> qq,point[N],key[N];

void dfs(int i)
{
	v[i]=1;
	for (int p=0;p<(int)point[i].size();p++)
	{
		int j=point[i][p];
		if (v[j]) continue;
		int k=key[i][p];
		pp+=k;
		dfs(j);
	}
}

void dfs2(int i,int pp)
{
	if (ans==-1 || pp<ans)
	{
		ans=pp;
		qq.clear();
	}
	if (ans==pp) qq.push_back(i);
	v[i]=0;
	for (int p=0;p<(int)point[i].size();p++)
	{
		int j=point[i][p];
		if (v[j]==0) continue;
		int k=key[i][p];
		if (k==1) dfs2(j,pp-1);
		else dfs2(j,pp+1);
	}
}

int main()
{
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		int j,k;
		cin>>j>>k;
		point[j].push_back(k);
		key[j].push_back(0);
		point[k].push_back(j);
		key[k].push_back(1);
	}
	ans=-1;
	pp=0;
	dfs(1);
	dfs2(1,pp);
	cout<<ans<<endl;
	sort(qq.begin(),qq.end());
	cout<<qq[0];
	for (int i=1;i<(int)qq.size();i++) cout<<' '<<qq[i];
	cout<<endl;
	return 0;
}