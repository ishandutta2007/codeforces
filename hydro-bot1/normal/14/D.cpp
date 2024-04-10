// Hydro submission #6221b5488331ffa528ce21ce@1646376264355
#include <bits/stdc++.h>
using namespace std;
vector<int> nodes[100005];
int ans,sum,a,b,y,s1[100005],s2[100005];
void dfs(int u,int from,int len)
{
	if(len>=sum)sum=len,y=u;
	int i,v,w,l=nodes[u].size();
	for(i=0;i<l;i++)
	{
		v=nodes[u][i];
		if((u==a&&v==b)||(u==b&&v==a)||v==from)continue;
		dfs(v,u,len+1);
	}
	return;
}
int main()
{
	int n,u,v,i,tmp;
	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		nodes[u].push_back(v);
		nodes[v].push_back(u);
		s1[i]=u;
		s2[i]=v;
	}
	for(i=1;i<n;i++)
	{
		a=s1[i],b=s2[i],sum=0;
		dfs(a,0,0);
		sum=0;
		dfs(y,0,0);
		tmp=sum,sum=0;
		dfs(b,0,0);
		sum=0;
		dfs(y,0,0);
		ans=max(ans,tmp*sum);
	}
	cout<<ans;
	return 0;
}