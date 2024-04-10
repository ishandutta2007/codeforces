#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define MAXN 600005
struct node
{
	int i,d;
	bool operator<(const node& y)const
	{
		return d<y.d;
	}
}a[MAXN];
int n,m=6,N,i,j,k,ans,d[10],s[MAXN];
int main()
{
	for(i=0;i<m;i++)scanf("%d",d+i);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&j);
		for(k=0;k<m;k++)
		{
			a[N].i=i;
			a[N++].d=j-d[k];
		}
	}
	sort(a,a+N);
	ans=1<<30;
	for(i=j=k=0;i<N;i++)
	{
		for(;j<N&&k<n;j++)
		{
			if(!s[a[j].i])k++;
			s[a[j].i]++;
		}
		if(k<n)break;
		ans=min(ans,a[j-1].d-a[i].d);
		s[a[i].i]--;
		if(!s[a[i].i])k--;
	}
	cout<<ans<<endl;
	return 0;
}