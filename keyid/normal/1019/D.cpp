#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=2005;

struct Point
{
	int x,y;

	Point(){}
	Point(int x,int y):x(x),y(y){}

	void read()
	{
		scanf("%d%d",&x,&y);
	}

	void output() const
	{
		printf("%d %d\n",x,y);
	}

	int quad() const
	{
		if (x>0&&y>=0) return 1;
		if (x<=0&&y>0) return 2;
		if (x<0&&y<=0) return 3;
		return 4;
	}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	LL operator * (const Point &b) const
	{
		return (LL)x*b.y-(LL)y*b.x;
	}

	LL operator % (const Point &b) const
	{
		return (LL)x*b.x+(LL)y*b.y;
	}
}p[MAXN];

struct Vec
{
	Point v;
	int p1,p2;
}a[MAXN*MAXN];

int n,id[MAXN],pos[MAXN];
LL S;

bool cmp(const Vec &a,const Vec &b)
{
	int q1=a.v.quad(),q2=b.v.quad();
	if (q1!=q2)
		return q1<q2;
	return a.v*b.v>0;
}

bool cmp2(int x,int y)
{
	return p[x].x!=p[y].x?p[x].x<p[y].x:p[x].y>p[y].y;
}

bool check(const Point &vc,const Point &p1,const Point &p2)
{
	int l=0,r=n-1;
	while (l<=r)
	{
		int m=l+r>>1;
		LL c=(p[id[m]]-p1)%vc;
		if (c==S)
		{
			puts("Yes");
			p[id[m]].output();
			p1.output();
			p2.output();
			return true;
		}
		if (c<S)
			l=m+1;
		else
			r=m-1;
	}
	return false;
}

int main()
{
	//freopen("read.txt","r",stdin);
	scanf("%d%lld",&n,&S);
	S*=2;
	for (int i=0;i<n;i++)
		p[i].read();
	int cnt=0;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i!=j)
			{
				Point t=p[i]-p[j];
				swap(t.x,t.y);
				t.x=-t.x;
				a[cnt++]={t,i,j};
			}
	sort(a,a+cnt,cmp);
	for (int i=0;i<n;i++)
		id[i]=i;
	sort(id,id+n,cmp2);
	for (int i=0;i<n;i++)
		pos[id[i]]=i;
	for (int i=0;i<cnt;i++)
	{
		if (check(a[i].v,p[a[i].p1],p[a[i].p2]))
			return 0;
		swap(pos[a[i].p1],pos[a[i].p2]);
		swap(id[pos[a[i].p1]],id[pos[a[i].p2]]);
	}
	printf("No");
	return 0;
}