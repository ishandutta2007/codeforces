// Hydro submission #62cd079c4125dc528b1ce199@1657603996212
#include<bits/stdc++.h>
using namespace std;
int n,fa[105],f[105],d;
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}

void merge(int x,int y)
{
	int u=find(x),v=find(y);
	if(u!=v) fa[u]=v; 
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
	    cin>>f[i];
	    fa[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		if(i>d) merge(i,i-d);
		if(i+d<=n) merge(i,i+d);
	}
	for(int i=1;i<=n;i++)
	{
		if(find(i)!=find(f[i]))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}