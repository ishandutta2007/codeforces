#include<bits/stdc++.h>
using namespace std;
#define MAXN 524288
#define ll long long
ll d[MAXN];
int n,m,M,i,j,a[MAXN],x[MAXN],y[MAXN],a2[MAXN],D[MAXN<<1];
char c[10];
set<pair<int,int> > s;
set<pair<int,int> >::iterator it;
vector<int> t[MAXN<<1],z;
set<int> T[MAXN<<1];
void fix(int R,int l,int r,int l1,int r1,int x)
{
	if(l1<=l&&r<=r1)
	{
		t[R].push_back(x);
		return;
	}
	int mid=l+r>>1;
	if(l1<=mid)fix(R<<1,l,mid,l1,r1,x);
	if(r1>mid)fix(R<<1|1,mid+1,r,l1,r1,x);
}
void work(int R,int l,int r)
{
	int mid=l+r>>1,i;
	ll j;
	D[R]+=t[R].size();
	for(auto x:t[R])
	{
		for(i=x;i<=M;i+=i&-i)d[i]+=a2[x];
		T[R].insert(x);
	}
	for(auto y:T[R])
	{
		for(i=y-1,j=0;i;i^=i&-i)j+=d[i];
		if(a2[y]<=j<<1)z.push_back(y);
	}
	for(auto y:z)T[R].erase(y);
	z.clear();
	if(l==r)
	{
		if(!T[R].empty()){
		for(i=*T[R].begin()-1,j=0;i;i^=i&-i)j+=d[i];
			if(!j)T[R].erase(T[R].begin());}
		printf("%d\n",max(D[R]-(int)T[R].size()-1,0));
		for(auto x:t[R])for(i=x;i<=M;i+=i&-i)d[i]-=a2[x];
		return;
	}
	T[R<<1]=T[R];
	T[R<<1|1]=T[R];
	T[R].clear();
	D[R<<1]=D[R<<1|1]=D[R];
	work(R<<1,l,mid);
	work(R<<1|1,mid+1,r);
	for(auto x:t[R])for(i=x;i<=M;i+=i&-i)d[i]-=a2[x];
}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s%d",c,&j);
		if(c[0]=='+')
		{
			a[++m]=j;
			x[m]=i;
			a2[m]=j;
			s.insert(make_pair(j,m));
		}
		else
		{
			it=s.lower_bound(make_pair(j,0));
			y[it->second]=i-1;
			s.erase(it);
		}
	}
	sort(a2+1,a2+m+1);
	M=unique(a2+1,a2+m+1)-a2-1;
	for(i=1;i<=m;i++)
	{
		a[i]=lower_bound(a2+1,a2+M+1,a[i])-a2;
		if(!y[i])y[i]=n;
		fix(1,1,n,x[i],y[i],a[i]);
	}
	work(1,1,n);
	return 0;
}