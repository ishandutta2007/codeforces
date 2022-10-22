#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
int t,n,m,i,j,k,d[MAXN],h[MAXN],ne[MAXN<<1],p[MAXN<<1],f[MAXN];
bool v[MAXN];
char c[MAXN];
bool work(int R)
{
	if(n<3)return 0;
	if(d[R]>2)return 1;
	if(d[R]==1)
	{
		int i,j;
		v[R]=1;
		for(i=h[R];i;i=ne[i])if(!v[p[i]])break;
		i=p[i];
		v[i]=1;
		for(j=h[i];j;j=ne[j])if(!v[p[j]])break;
		j=p[j];
		if(c[i]=='W'||c[j]=='W'||d[i]>2)return 1;
		n-=2;
		d[j]--;
		return work(j);
	}
	int i,j;
	for(i=h[R],j=0;i;i=ne[i])if(!v[p[i]]&&c[p[i]]=='W')j++;
	if(j)return 1;
	return n!=3;
}
bool check(int x)
{
	int i,j;
	for(i=h[x],j=0;i;i=ne[i])if(p[i]!=f[x])
	{
		f[p[i]]=x;
		if(check(p[i]))return 1;
		if(c[p[i]]=='W')j++;
	}
	if(c[x]=='W'&&(j>=2||c[f[x]]=='W'&&c[f[f[x]]]=='W'))return 1;
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fill(d+1,d+n+1,0);
		fill(h+1,h+n+1,0);
		fill(v+1,v+n+1,0);
		m=0;
		for(i=1;i<n;i++)
		{
			scanf("%d%d",&j,&k);
			p[++m]=k;
			ne[m]=h[j];
			h[j]=m;
			p[++m]=j;
			ne[m]=h[k];
			h[k]=m;
			d[j]++;
			d[k]++;
		}
		scanf("%s",c+1);
		if(n<3)
		{
			puts("Draw");
			continue;
		}
		for(i=1;i<=n;i++)if(d[i]>3)break;
		if(i<=n)
		{
			puts("White");
			continue;
		}
		f[1]=0;
		if(check(1))
		{
			puts("White");
			continue;
		}
		for(i=1;i<=n;i++)if(c[i]=='W')break;
		if(i<=n)
		{
			if(work(i))puts("White");
			else puts("Draw");
			continue;
		}
		if(n<5)
		{
			puts("Draw");
			continue;
		}
		for(i=1;i<=n;i++)if(d[i]>2)break;
		if(i>n)
		{
			puts("Draw");
			continue;
		}
		for(j=h[i],k=0;j;j=ne[j])if(d[p[j]]==1)k++;
		if(k<2)
		{
			puts("White");
			continue;
		}
		for(j=h[i];j;j=ne[j])if(d[p[j]]>1)break;
		v[i]=1;
		c[p[j]]='W';
		d[p[j]]--;
		n-=3;
		if(work(p[j]))puts("White");
		else puts("Draw");
	}
	return 0;
}