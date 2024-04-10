#include<bits/stdc++.h>
using namespace std;
vector<int> G[100100];
int n;
int lsz[100100];
int sz[100100];
void dfs(int x,int fa)
{
	sz[x]=1;
	lsz[x]=0;
	for(int i=0;i<(int)(G[x].size());i++)
		if(G[x][i]!=fa)
		{
			dfs(G[x][i],x);
			lsz[x]=max(lsz[x],sz[G[x][i]]);
			sz[x]+=sz[G[x][i]];
		}
//	cout<<x<<" "<<sz[x]<<" "<<lsz[x]<<endl;
	lsz[x]=max(lsz[x],n-sz[x]);
//	cout<<x<<" "<<sz[x]<<" "<<lsz[x]<<endl;
}
bool findd;
int aa,afa;
void dfs2(int x,int fa)
{
	if(sz[x]==1)
	{
		aa=x;
		afa=fa;
		findd=true;
		return ;
	}
	for(int i=0;i<(int)(G[x].size());i++)
		if(G[x][i]!=fa)
		{
			dfs2(G[x][i],x);
			if(findd)
				return ;
		}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			G[i].clear();
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			G[a].push_back(b);
			G[b].push_back(a);
		}
		dfs(0,-1);
		int a=-1,b=-1;
		int mn=*min_element(lsz,lsz+n);
		for(int i=0;i<n;i++)
		{
			if(lsz[i]==mn)
			{
				if(a==-1)
					a=i;
				else	b=i;
			}
		//	cout<<i<<" "<<lsz[i]<<endl;
			
		}
		if(b==-1)
		{
			cout<<1<<" "<<G[0][0]+1<<endl<<1<<" "<<G[0][0]+1<<endl;
			continue;
		}
		if(sz[a]>sz[b])
			swap(a,b);
		findd=false;
		dfs2(a,b);
		//puts("...");
		cout<<aa+1<<" "<<afa+1<<endl;
		cout<<aa+1<<" "<<b+1<<endl;
	}
	return 0;
}