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

int sz[maxn],vis[maxn],p[maxn];
vector <int> mp[maxn];
int n,root;

void del(int x)
{
	vis[x]=1;
	cout<<x<<endl;
	for(int i=0;i<mp[x].size();i++)
		if(!vis[mp[x][i]]) del(mp[x][i]);
}

void dfs(int x)
{
	sz[x]=1;
	for(int i=0;i<mp[x].size();i++)
		dfs(mp[x][i]),sz[x]+=sz[mp[x][i]];
	if(!(sz[x]&1)) del(x);
}

int main()
{
	n=read();
	if(n&1) cout<<"YES"<<endl;
	else {cout<<"NO"<<endl; return 0;}
	for(int i=1;i<=n;i++)
	{
		p[i]=read();
		if(p[i]) mp[p[i]].push_back(i);
		else root=i;
	}
	dfs(root); del(root);
	return 0;
}