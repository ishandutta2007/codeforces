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

map <string,int> mp;
string s;
vector <int> g[maxn];
int pos[maxn],w[maxn];
int n,k,m;
ll ans;

int main()
{
	n=read(); k=read(); m=read();
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		mp[s]=i;
	}
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=k;i++)
	{
		int x=read();
		for(int j=1;j<=x;j++)
		{
			int k=read();
			g[i].push_back(w[k]);
			pos[k]=i;
		}
		sort(g[i].begin(),g[i].end());
	}
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		int tmp=pos[mp[s]];
		ans+=g[tmp][0];
	}
	cout<<ans;
	return 0;
}