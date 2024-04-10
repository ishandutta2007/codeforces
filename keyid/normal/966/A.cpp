#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define mp make_pair
#define fi first
#define sc second
#define pb push_back

const int MAXN=100005;

int c1,c2,p1[MAXN],p2[MAXN];

int query(int x1,int y1,int x2,int y2,int v,int c,int *p)
{
	if (x1==x2)
		return abs(y1-y2);
	int k=lower_bound(p,p+c,y1)-p,r1=INT_MAX,r2=INT_MAX;
	if (k<c)
	{
		r1=abs(p[k]-y1);
		r1+=(abs(x1-x2)-1)/v+1;
		r1+=abs(p[k]-y2);
	}
	if (k>0)
	{
		k--;
		r2=abs(p[k]-y1);
		r2+=(abs(x1-x2)-1)/v+1;
		r2+=abs(p[k]-y2);
	}
	return min(r1,r2);
}

int main()
{
	int n,m,v;
	scanf("%d%d%d%d%d",&n,&m,&c1,&c2,&v);
	for (int i=0;i<c1;i++)
		scanf("%d",&p1[i]);
	for (int i=0;i<c2;i++)
		scanf("%d",&p2[i]);
	int q;
	scanf("%d",&q);
	while (q--)
	{
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int ans=min(query(x1,y1,x2,y2,1,c1,p1),query(x1,y1,x2,y2,v,c2,p2));
		printf("%d\n",ans);
	}
	return 0;
}