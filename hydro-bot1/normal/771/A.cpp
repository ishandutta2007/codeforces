// Hydro submission #62d29cd6b36e4a12382afbcb@1657969878485
#include<bits/stdc++.h>
using namespace std;
long long s[150001],t;
int fa[150001];
int Find(int x)
{   
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
void Union(int fx,int fy)
{
    fa[Find(fx)]=Find(fy);
}
int main()
{
    int n,m,x,y,fx,fy,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	fa[i]=i,s[i]=1;
	for(i=1;i<=m;i++)
	{
		cin>>x>>y;
		fx=Find(x),fy=Find(y);
		if(fx!=fy)
		fa[fx]=fy,s[fy]+=s[fx];
	}
	for(i=1;i<=n;i++)
	if(Find(i)==i)
	t+=s[i]*(s[i]-1)/2;
	printf(t==m?"YES\n":"NO\n");
    return 0;
}