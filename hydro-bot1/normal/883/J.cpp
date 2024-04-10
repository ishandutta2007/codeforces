// Hydro submission #62d2a0e875c677124c8ed04e@1657970921527
#include<bits/stdc++.h>
using namespace std;
long long a[100001],s[100001],t;
int v[100002],mx,c,as;
struct node{
	long long b,p;
	const char operator<(node x)const{
		return p>x.p;
	}
}d[100002];
bool cmp(node x,node y)
{
	return x.b<y.b;
}
priority_queue<node> q;
priority_queue<int> qq;
int main()
{
	int n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	cin>>a[i],s[i]=s[i-1]+a[i];
	for(i=1;i<=m;i++)
	cin>>d[i].b;
	for(i=1;i<=m;i++)
	cin>>d[i].p;
	sort(d+1,d+m+1,cmp);
	for(i=n;i>=1;i--)
	if(a[i]>mx)
	v[++c]=i,mx=a[i];
	v[c+1]=0;
	d[m+1].p=4e18,q.push(d[m+1]);
	qq.push(0);
	for(i=c;i>=1;i--)
	{
		while(m&&(d[m].b>a[v[i-1]]))
		q.push(d[m--]);
		t+=s[v[i]]-s[v[i+1]];
		while(q.top().p<=t||q.top().p<qq.top())
		if(q.top().b>a[v[i]]) q.pop();
		else
		{
			if(q.top().p>t)
			t+=qq.top(),qq.pop();
			else as++;
			t-=q.top().p;
			qq.push(q.top().p);
			q.pop();
		}
	}
	printf("%d\n",as);
	return 0;
}