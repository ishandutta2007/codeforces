#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=3e5+5;
pii p[N];int q[N];

bool p_xiao(int i,int j)
{
	return p[i].first!=p[j].first?p[i].first<p[j].first:p[i].second>p[j].second;
}

int main()
{
	int n;cin>>n;
	rep(i,1,n)scanf("%d%d",&p[i].first,&p[i].second);
	rep(i,1,n)q[i]=i;
	sort(q+1,q+n+1,p_xiao);
	for(int i=n,mn=q[n];--i;)
	{
		int x=q[i];
		if(p[mn].second<=p[x].second)
		{
			cout<<mn<<" "<<x;
			exit(0);
		}
		else mn=x;
	}
	puts("-1 -1");
}