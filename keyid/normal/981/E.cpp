#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=10005;

struct segment
{
	int l,r,x;
}a[MAXN];

bitset <MAXN> b[20],ans;

void solve(int l,int r,int cur,int q)
{
	for (int i=0;i<q;i++)
		if (a[i].l<=l&&a[i].r>=r)
		{
			b[cur]=b[cur]|(b[cur]<<a[i].x);
			q--;
			swap(a[i],a[q]);
			i--;
		}
	if (l==r)
		ans|=b[cur];
	else
	{
		int m=l+r>>1;
		int t=q;
		for (int i=0;i<t;i++)
			if (a[i].l>m)
			{
				t--;
				swap(a[i],a[t]);
				i--;
			}
		b[cur+1]=b[cur];
		solve(l,m,cur+1,t);
		t=q;
		for (int i=0;i<t;i++)
			if (a[i].r<=m)
			{
				t--;
				swap(a[i],a[t]);
				i--;
			}
		b[cur+1]=b[cur];
		solve(m+1,r,cur+1,t);
	}
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	for (int i=0;i<q;i++)
		scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].x);
	b[0][0]=1;
	solve(1,n,0,q);
	int sum=0;
	for (int i=1;i<=n;i++)
		if (ans[i])
			sum++;
	printf("%d\n",sum);
	for (int i=1;i<=n;i++)
		if (ans[i])
			printf("%d ",i);
	return 0;
}