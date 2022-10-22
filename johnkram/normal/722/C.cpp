#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define MAXN 100005
#define ll long long
int n,i,a[MAXN],f[MAXN];
bool b[MAXN];
ll s[MAXN],ans[MAXN];
int get(int x)
{
	if(f[x]==x)return x;
	return f[x]=get(f[x]);
}
void merge(int x,int y)
{
	x=get(x);
	y=get(y);
	f[x]=y;
	s[y]+=s[x];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",s+i);
		f[i]=i;
	}
	for(i=1;i<=n;i++)scanf("%d",a+i);
	for(i=n;i;i--)
	{
		b[a[i]]=1;
		if(b[a[i]+1])merge(a[i],a[i]+1);
		if(b[a[i]-1])merge(a[i],a[i]-1);
		ans[i-1]=max(ans[i],s[get(a[i])]);
	}
	for(i=1;i<=n;i++)printf("%I64d\n",ans[i]);
	return 0;
}