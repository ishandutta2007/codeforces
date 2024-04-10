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
#define maxn 200005
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

int n,m,cnt;
bool vis[maxn];
queue <int> que;
struct node{int a,b;};
set <int> s;
vector <int> vec;

inline bool operator < (node x,node y)
{
	if(x.a==y.a) return x.b<y.b;
	return x.a<y.a;
}

map <node,int> p;

inline void bfs(int x)
{
	que.push(x); vis[x]=1; s.erase(x);
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(set <int>::iterator it=s.begin();it!=s.end();it++)
		{
			int i=*it;
			if(p[(node){u,i}]==0)
			{
				vis[i]=1;
				que.push(i);
				vec.push_back(i);
			}
		}
		for(int i=0;i<vec.size();i++) s.erase(vec[i]);
		vec.clear();
	}
	//for(int i=1;i<=n;i++) cout<<vis[i]<<" "; cout<<endl;
}

int main()
{
	n=read(); m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		p[node{u,v}]=1; p[(node){v,u}]=1;
	}
	for(int i=1;i<=n;i++) s.insert(i);
	for(int i=1;i<=n;i++) if(!vis[i]) bfs(i),cnt++;
	cout<<cnt-1<<endl;
	return 0;
}