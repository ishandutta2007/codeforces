#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;
typedef set <int> :: iterator sit;

const int MAXN=100005;

#define pb push_back
#define fi first
#define sc second
#define mp make_pair

struct query
{
	int op,l,r,add;
}qu[MAXN*14];

set <int> s[MAXN];
int n,a[MAXN];
LL C[MAXN],ans[MAXN];

bool cmp(const query &a,const query &b)
{
	return a.l<b.l;
}

void add(int x,int d)
{
	for (;x<=n;x+=x&-x)
		C[x]+=d;
}

void clear(int x)
{
	for (;x<=n;x+=x&-x)
		C[x]=0;
}

LL sum(int x)
{
	LL ret=0;
	for (;x;x-=x&-x)
		ret+=C[x];
	return ret;
}

void solve(int l,int r)
{
	if (l==r)
		return;
	int m=l+r>>1;
	solve(l,m);
	solve(m+1,r);
	int head=l;
	for (int i=m+1;i<=r;i++)
		if (qu[i].op==2)
		{
			while (head<=m&&qu[head].l<=qu[i].l)
			{
				if (qu[head].op==1)
					add(qu[head].r,qu[head].add);
				head++;
			}
			ans[qu[i].add]+=sum(qu[i].r);
		}
	for (int i=l;i<=m;i++)
		if (qu[i].op==1)
			clear(qu[i].r);
	sort(qu+l,qu+r+1,cmp);
}

int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		s[i].insert(0);
		s[i].insert(n+1);
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s[a[i]].insert(i);
	}
	int cnt=0,cq=0;
	for (int i=1;i<=n;i++)
		for (sit it=s[i].begin();it!=s[i].end();)
		{
			sit t=it;
			++t;
			if (it!=s[i].begin()&&t!=s[i].end())
			{
				qu[cnt++]={1,1,*t,*t-*it};
				qu[cnt++]={1,*it+1,*t,-(*t-*it)};
			}
			it=t;
		}
	for (int i=0;i<m;i++)
	{
		int op,p,x;
		scanf("%d%d%d",&op,&p,&x);
		if (op==1)
		{
			sit it=s[a[p]].lower_bound(p),it1=it,it2=it;
			it1--;
			it2++;
			qu[cnt++]={1,1,*it,-(*it-*it1)};
			qu[cnt++]={1,1,*it2,(*it-*it1)};
			qu[cnt++]={1,*it1+1,*it,(*it-*it1)};
			qu[cnt++]={1,*it1+1,*it2,-(*it-*it1)};
			qu[cnt++]={1,*it1+1,*it2,-(*it2-*it)};
			qu[cnt++]={1,*it+1,*it2,(*it2-*it)};
			s[a[p]].erase(p);
			a[p]=x;
			s[x].insert(p);
			it=s[x].lower_bound(p);
			it1=it;
			it2=it;
			it1--;
			it2++;
			qu[cnt++]={1,1,*it,*it-*it1};
			qu[cnt++]={1,1,*it2,-(*it-*it1)};
			qu[cnt++]={1,*it1+1,*it,-(*it-*it1)};
			qu[cnt++]={1,*it1+1,*it2,*it-*it1};
			qu[cnt++]={1,*it1+1,*it2,*it2-*it};
			qu[cnt++]={1,*it+1,*it2,-(*it2-*it)};
			//printf("%d %d %d %d\n",*it1,*it,*it2,*it2-*it);
		}
		else
			qu[cnt++]={2,p,x,cq++};
	}
	solve(0,cnt-1);
	for (int i=0;i<cq;i++)
		printf("%lld\n",ans[i]);
	return 0;
}