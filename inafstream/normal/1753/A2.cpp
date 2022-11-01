#include <bits/stdc++.h>
#define rep(i,n) for (int i=1;i<=(n);i++)
#define per(i,n) for (int i=(n);i>=1;i--)
using namespace std;

int n,m;
int a[200005],b[200005];

void solve()
{
	int s=0;
	scanf("%d",&n);
	rep(i,n)
	{
		scanf("%d",&a[i]);
		b[i]=1;
		s+=a[i];
	}
	if(s&1)
	{
		puts("-1");
		return;
	}

	for(int i=2;i<=n;i++)if(b[i-1]==1)
	{
		if(a[i]==1&&s>0)
		{
			s-=2;b[i]=-1;
		}
		else if(a[i]==-1&&s<0)
		{
			s+=2;b[i]=-1;
		}
	}
	if(s)
	{
		puts("-1");
		return;
	}

	vector<pair<int,int>> v;
	int lst=1;
	rep(i,n)
	{
		if(i==n||b[i]==b[i+1])
		{
			v.push_back(make_pair(lst,i));
			lst=i+1;
		}
	}

	printf("%d\n",(int)v.size());
	for(auto u:v) printf("%d %d\n",u.first,u.second);
}



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}