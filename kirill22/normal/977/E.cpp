#include<bits/stdc++.h>
#define maxn 300000
using namespace std;

vector<int>v[maxn];
int vis[maxn];
 
int ver=0,edge=0;
int flag=0;
void dfs(int sx)
{
	
	
	if(v[sx].size()!=2) {
		flag=1;	
		
		for(int i=0;i<v[sx].size();i++)
		{
			if(!vis[v[sx][i]])
			{
				vis[v[sx][i]]=1;
				dfs(v[sx][i]);
			}
		}
		//return;
	}
	
	else
	{
		if(!vis[v[sx][0]])  
		{
			vis[v[sx][0]]=1;
			dfs(v[sx][0]);
		}
		if(!vis[v[sx][1]])  
		{
			vis[v[sx][1]]=1;
			dfs(v[sx][1]);
		}
	}
	
	//return;
	
}

int main()
{
	
	
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		v[a].push_back(b);
		v[b].push_back(a);
		
	}
	int cnt=0;
	
	for(int i=1;i<=n;i++)
	{
		
			
			if(!vis[i])
			{
				flag=0;
			
				dfs(i);
				if(!flag) cnt++;
			}
	}
	
	printf("%d\n",cnt);
}