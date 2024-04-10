#include<bits/stdc++.h>
using namespace std;
char S[5050][5050];
void findloop(vector<int> c)
{
//	puts("...");
	if(S[c[2]][c[0]]=='1')
	{
		cout<<c[0]+1<<" "<<c[1]+1<<" "<<c[2]+1<<endl;
		exit(0);
	}
	c.erase(c.begin()+1);
	findloop(c);
}
int color[5050];
bool f1,f2;
int st;
int n;
vector<int> cycle;
bool vis[5050];
void dfs(int x)
{
	if(vis[x])
		return ;
	vis[x]=true;
	color[x]=1;
	for(int i=0;i<n;i++)
		if(S[x][i]=='1')
		{
			if(color[i]==1)
			{
				f1=true;
				st=i;
				cycle.push_back(x);
				return ;
			}
			if(!color[i])
				dfs(i);
			if(f1)
			{
				if(!f2)
					cycle.push_back(x);
				if(x==st)
				{
					f2=true;
					return ;
				}
				return ;
			}
		}
	color[x]=2;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%s",S+i);
	for(int i=0;i<n;i++)
		if(!vis[i])
		{
			dfs(i);
			if(f1)
			{
				reverse(cycle.begin(),cycle.end());
				findloop(cycle);
				return 0;
			}
		}
	puts("-1");
	return 0;
}