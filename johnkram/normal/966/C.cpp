#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,m,i,j,k,b[MAXN],h,ne[MAXN],pr[MAXN],c[60];
ll a[MAXN];
vector<int> d[60];
int get(ll x,int y)
{
	for(;1LL<<y+1<=x;y++);
	return y;
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%I64d",a+i);
	sort(a+1,a+n+1,greater<ll>());
	for(i=n;i;i--)b[i]=get(a[i],b[i+1]);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<b[i];j++)if(a[i]>>j&1)c[j]++;
		d[b[i]].push_back(i);
	}
	for(i=0;i<60;i++)if(d[i].size()>c[i]+1)break;
	if(i<60)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(i=59;~i;i--)if(!d[i].empty())
	{
		ne[d[i][0]]=h;
		if(h)pr[h]=d[i][0];
		h=d[i][0];
		m=d[i].size();
		for(j=1,k=ne[h];j<m;j++)
		{
			for(;k;k=ne[k])if(a[k]>>i&1)break;
			ne[d[i][j]]=ne[k];
			pr[d[i][j]]=k;
			ne[pr[d[i][j]]]=d[i][j];
			if(ne[d[i][j]])pr[ne[d[i][j]]]=d[i][j];
			k=ne[d[i][j]];
		}
	}
	for(i=h;i;i=ne[i])cout<<a[i]<<' ';
	return 0;
}