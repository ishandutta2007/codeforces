#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXN=100005,INF=0x3f3f3f3f;

int n,d[MAXN],a[MAXN],C[MAXN],l[MAXN],r[MAXN];

void add(int x,int d)
{
	for (;x;x-=x&-x)
		C[x]=max(C[x],d);
}

int query(int x)
{
	int ret=0;
	for (;x<=n;x+=x&-x)
		ret=max(ret,C[x]);
	return ret;
}

void add2(int x,int d)
{
	for (;x<=n;x+=x&-x)
		C[x]=max(C[x],d);
}

int query2(int x)
{
	int ret=0;
	for (;x;x-=x&-x)
		ret=max(ret,C[x]);
	return ret;
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		d[l]++;
		d[r+1]--;
	}
	for (int i=1;i<=m;i++)
		a[i]=a[i-1]+d[i];
	for (int i=1;i<=m;i++)
		a[i]++;
	for (int i=1;i<=m;i++)
	{
		l[i]=query2(a[i])+1;
		add2(a[i],l[i]);
	}
	memset(C,0,sizeof(C));
	for (int i=m;i>=1;i--)
	{
		r[i]=query2(a[i])+1;
		add2(a[i],r[i]);
	}
	int ans=0;
	for (int i=1;i<=m;i++)
		ans=max(ans,l[i]+r[i]-1);
	printf("%d",ans);
	return 0;
}