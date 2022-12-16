#include<bits/stdc++.h>
using namespace std;
int n,k,i,t;
int Ask(vector<int> a,vector<int> b)
{
	char c[10];
	printf("? %d %d\n",a.size(),b.size());
	for(int i=0;i<a.size();++i)
		printf("%d ",a[i]);
	printf("\n");
	for(int i=0;i<b.size();++i)
		printf("%d ",b[i]);
	printf("\n");
	fflush(stdout);
	scanf("%s",c);
	if(c[0]=='F')
		return 1;
	if(c[0]=='S')
		return 2;
	if(c[0]=='E')
		return 0;
}
vector<int> ans,op;
void G2(vector<int> p,vector<int> q)
{
	int i;
	if(p.size()>=q.size())
	{
		op=p;
		ans=q;
		return;
	}
	vector<int> a,b;
	for(i=0;i<p.size();++i)
		a.push_back(q[i]);
	int x=Ask(p,a);
	if(x==1)
	{
		op=p;
		ans=a;
	}
	else
	{
		for(i=0;i<p.size();++i)
			a.push_back(p[i]);
		for(i=p.size();i<q.size();++i)
			b.push_back(q[i]);
		G2(a,b);
	}
}
void G3(vector<int> p,vector<int> q)
{
	if(q.size()==1)
	{
		printf("! %d\n",q[0]);
		fflush(stdout);
		return;
	}
	int i;
	vector<int> a,b;
	int n=q.size()/2;
	for(i=0;i<n;++i)
	{
		a.push_back(p[i]);
		b.push_back(q[i]);
	}
	if(Ask(a,b)==1)
		G3(p,b);
	else
	{
		b.clear();
		for(i=n;i<q.size();++i)
			b.push_back(q[i]);
		G3(p,b);
	}
}
int a[1005];
int main()
{
	scanf("%d",&t);
	srand(19263);
	while(t--)
	{
		scanf("%d %d",&n,&k);
		op.clear();
		ans.clear();
		vector<int> p,q;
		for(i=1;i<=n;++i)
			a[i]=i;
		random_shuffle(a+1,a+1+n);
		int x=a[1];
		for(i=2;i<=n&&i<=25;++i)
		{
			p.clear();
			q.clear();
			p.push_back(x);
			q.push_back(a[i]);
			if(Ask(p,q)==2)
				x=a[i];
		}
		p.clear(),q.clear();
		p.push_back(x);
		for(i=1;i<=n;++i)
			if(i!=x)
				q.push_back(i);
		G2(p,q);
		G3(op,ans);
	}
}