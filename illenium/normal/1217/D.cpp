#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 5005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

struct node{int u,v,col;}e[maxn];
vector <int> mp[maxn];
queue <int> que;
int ind[maxn];
bool vis[maxn];

int main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		e[i].u=read(),e[i].v=read();
		mp[e[i].u].push_back(e[i].v); ind[e[i].v]++;
	}
	for(int i=1;i<=n;i++) if(ind[i]==0) que.push(i),vis[i]=1;
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i];
			ind[v]--;
			if(ind[v]==0) que.push(v),vis[v]=1;
		}
	}
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(ind[i]!=0)
		{
			flag=1;
			puts("2"); break;
		}
		
	}
	if(flag==0)
	{
		puts("1");
		for(int j=1;j<=m;j++) printf("1 ");
	}
	if(flag==1)
	{
		for(int i=1;i<=m;i++)
		{
			if(e[i].u>e[i].v) printf("1 ");
			else printf("2 ");
		}
	}
	return 0;
}