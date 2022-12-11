#include <bits/stdc++.h>
using namespace std;

const int MAXN=200005;

int p[MAXN],a[MAXN],b[MAXN];

struct data
{
	int x;

	bool operator < (const data &y) const
	{
		return p[x]<p[y.x];
	}
};

set <data> s[4];

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&p[i]);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for (int i=0;i<n;i++)
		scanf("%d",&b[i]);
	for (int i=0;i<n;i++)
	{
		s[a[i]].insert((data){i});
		s[b[i]].insert((data){i});
	}
	int m;
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int c;
		scanf("%d",&c);
		if (s[c].empty())
			printf("-1 ");
		else
		{
			data t=*s[c].begin();
			s[a[t.x]].erase(t);
			s[b[t.x]].erase(t);
			printf("%d ",p[t.x]);
		}
	}
	return 0;
}