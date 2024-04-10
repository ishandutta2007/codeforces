#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int n,ind[maxn],U[maxn],V[maxn],ans[maxn],f;
vector <int> mp[maxn];

int main()
{
	n=read();;
	for(int i=1;i<=n-1;i++)
	{
		int u=read(),v=read();
		mp[u].push_back(i),mp[v].push_back(i);
		ind[u]++; ind[v]++;
	}
	for(int i=1;i<=n;i++) if(ind[i]>=3)
	{
		ans[mp[i][0]]=-1;
		ans[mp[i][1]]=1;
		ans[mp[i][2]]=2; f=1; break;
	}
	if(f==1)
	{
		int cnt=3;
		for(int i=1;i<n;i++)
		{
			if(ans[i]) continue;
			ans[i]=cnt++;
		}
		for(int i=1;i<=n-1;i++)
			if(ans[i]==-1) puts("0"); else printf("%d\n",ans[i]);
	}
	else
	{
		for(int i=0;i<=n-2;i++) printf("%d\n",i);
	}
	return 0;
}