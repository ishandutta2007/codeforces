#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int MAXN=400005;

struct query
{
	int a,b,id;
}q[MAXN];

int nc,h[MAXN],l[MAXN],r[MAXN],ans[MAXN],num[MAXN*2],C[MAXN*2];
bool flag[MAXN];
vector <int> p[MAXN],last,t;

bool cmp(const query &e1,const query &e2)
{
	return e1.a<e2.a;
}

inline int getmax(int x)
{
	int ret=0;
	while (x)
	{
		ret=max(ret,C[x]);
		x-=x&-x;
	}
	return ret;
}

inline void update(int x,int d)
{
	while (x<=nc)
	{
		C[x]=max(C[x],d);
		x+=x&-x;
	}
}

inline int getmax2(int x)
{
	int ret=0;
	while (x<=nc)
	{
		ret=max(ret,C[x]);
		x+=x&-x;
	}
	return ret;
}

inline void update2(int x,int d)
{
	while (x)
	{
		C[x]=max(C[x],d);
		x-=x&-x;
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&h[i]);
		num[nc++]=h[i];
	}
	for (int i=0;i<m;i++)
	{
		scanf("%d%d",&q[i].a,&q[i].b);
		q[i].id=i;
		num[nc++]=q[i].b;
	}
	sort(num,num+nc);
	nc=unique(num,num+nc)-num;
	for (int i=1;i<=n;i++) h[i]=upper_bound(num,num+nc,h[i])-num;
	for (int i=0;i<m;i++) q[i].b=upper_bound(num,num+nc,q[i].b)-num;
	int lis=0;
	for (int i=1;i<=n;i++)
	{
		int k=getmax(h[i]-1)+1;
		update(h[i],k);
		p[k].pb(i);
		lis=max(lis,k);
	}
	fill(C,C+nc+1,0);
	h[n+1]=INT_MAX;
	last.pb(n+1);
	for (int i=lis;i>0;i--)
	{
		int _max=0,head=0;
		for (int j=p[i].size()-1;j>=0;j--)
		{
			while (head<last.size()&&last[head]>p[i][j]) _max=max(_max,h[last[head++]]);
			if (_max>h[p[i][j]]) t.pb(p[i][j]);
		}
		if (t.size()==1) flag[t[0]]=true;
		swap(last,t);
		t.clear();
	}
	sort(q,q+m,cmp);
	int head=1;
	for (int i=0;i<m;i++)
	{
		while (head<q[i].a)
		{
			int k=getmax(h[head]-1)+1;
			update(h[head++],k);
		}
		l[i]=getmax(q[i].b-1);
	}
	fill(C,C+nc+1,0);
	head=n;
	for (int i=m-1;i>=0;i--)
	{
		while (head>q[i].a)
		{
			int k=getmax2(h[head]+1)+1;
			update2(h[head--],k);
		}
		r[i]=getmax2(q[i].b+1);
	}
	for (int i=0;i<m;i++) ans[q[i].id]=max(flag[q[i].a]?lis-1:lis,l[i]+r[i]+1);
	for (int i=0;i<m;i++) printf("%d\n",ans[i]);
	return 0;
}