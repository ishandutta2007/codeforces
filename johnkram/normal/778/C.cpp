#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
int n,m,N,i,j,k,h[MAXN],ne[MAXN<<1],p[MAXN<<1],c[MAXN<<1][26],f[MAXN],s[MAXN<<1],d[MAXN],ans[MAXN];
char w[MAXN<<1],x[10];
int merge(int a,int b)
{
	if(!a||!b)return a|b;
	int x=++N,i;
	for(i=0,s[x]=1;i<26;i++)s[x]+=s[c[x][i]=merge(c[a][i],c[b][i])];
	return x;
}
void dfs(int x)
{
	int i,j;
	for(s[x]=1,i=h[x];i;i=ne[i])if(p[i]!=f[x])
	{
		d[p[i]]=d[x]+1;
		f[p[i]]=x;
		c[x][w[i]-'a']=p[i];
		dfs(p[i]);
		s[x]+=s[p[i]];
	}
	ans[d[x]]+=s[x];
	for(i=j=0;i<26;i++)j=merge(j,c[x][i]);
	N=n;
	ans[d[x]]-=max(s[j],1);
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%s",&j,&k,x);
		p[++m]=k;
		ne[m]=h[j];
		w[m]=x[0];
		h[j]=m;
		p[++m]=j;
		ne[m]=h[k];
		w[m]=x[0];
		h[k]=m;
	}
	N=n;
	dfs(1);
	for(i=j=0;i<n;i++)if(ans[i]>ans[j])j=i;
	printf("%d\n%d\n",n-ans[j],j+1);
	return 0;
}