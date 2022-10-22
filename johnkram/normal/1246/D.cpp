#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 1000005
#define P 1000000007
vector<int> c[MAXN];
int n,M,m,i,j,s[MAXN],a[MAXN],ans[MAXM];
void dfs(int x)
{
	s[x]=1;
	for(auto i:c[x])
	{
		dfs(i);
		s[x]=max(s[x],s[i]+1);
	}
}
bool cmp(int x,int y)
{
	if(s[x]==s[y])return x<y;
	return s[x]<s[y];
}
void work(int x)
{
	sort(c[x].begin(),c[x].end(),cmp);
	int j,N=0;
	a[M++]=x;
	for(auto i:c[x])
	{
		work(i);
		for(j=0;j<N;j++)ans[m++]=i;
		N=s[i];
	}
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d",&j);
		c[j].push_back(i);
	}
	dfs(0);
	work(0);
	for(i=0;i<n;i++)printf("%d%c",a[i],i==n-1?'\n':' ');
	printf("%d\n",m);
	for(i=0;i<m;i++)printf("%d%c",ans[i],i==m-1?'\n':' ');
	return 0;
}