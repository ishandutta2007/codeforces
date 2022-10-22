#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
struct node
{
	int x,y;
	bool operator<(const node& b)const
	{
		if(x==b.x)return y<b.y;
		return x<b.x;
	}
}a[MAXN],b[MAXN],t;
int N,n,m,i,j,l,r;
ll ans;
multiset<int> s,s1;
void work(node* a,int n)
{
	sort(a+1,a+n+1);
	s.clear();
	s1.clear();
	for(i=1;i<=n;i++)s1.insert(a[i].y);
	for(i=1;i<=n;i=j)
	{
		for(j=i;j<=n&&a[i].x==a[j].x;j++)
		{
			s.insert(a[j].y);
			s1.erase(s1.find(a[j].y));
		}
		l=-10000000;
		r=10000000;
		if(!s.empty())
		{
			l=max(l,*s.begin());
			r=min(r,*s.rbegin());
		}
		if(!s1.empty())
		{
			l=max(l,*s1.begin());
			r=min(r,*s1.rbegin());
		}
		if(j<=n)ans+=(ll)(a[j].x-a[i].x)*max(r-l,0);
	}
}
int main()
{
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d",&t.x,&t.y);
		t.x+=t.y;
		t.y=t.x-2*t.y;
		if(t.x&1)a[++n]=t;
		else b[++m]=t;
	}
	work(a,n);
	work(b,m);
	cout<<ans/4<<endl;
	return 0;
}