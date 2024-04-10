#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 505
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int ind[maxn],tin[maxn];
vector <int> mp[maxn];
queue <int> que;

bool topo(int n)
{
	int cnt=0;
	for(int i=1;i<=n;i++) if(tin[i]==0) que.push(i),cnt++;
	while(!que.empty())
	{
		int now=que.front(); que.pop();
		for(int i=0;i<mp[now].size();i++)
		{
			tin[mp[now][i]]--;
			if(tin[mp[now][i]]==0) que.push(mp[now][i]),cnt++;
		}
	}
	return cnt==n;
}

int main()
{
	int n,m;
	n=read(); m=read();
	for(int i=0;i<m;i++)
	{
		int u,v;
		u=read(); v=read();
		ind[v]++;
		mp[u].push_back(v);
	}
	for(int i=1;i<=n;i++)
	{
		if(ind[i]!=0)
		{
			for(int j=1;j<=n;j++) tin[j]=ind[j];
			tin[i]--;
			if(topo(n)) {puts("YES"); return 0;}
		}
	}
	puts("NO");
	return 0;
}