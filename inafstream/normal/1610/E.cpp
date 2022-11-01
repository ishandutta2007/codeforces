#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;


int n,ans;
int a[200005],pre[200005];
int f[200005],g[200005];
map<int,int> lst;

set<pair<int,int> > s; 

void push(int x,int v)
{
	set<pair<int,int> >::iterator it=s.upper_bound(make_pair(x,0x7fffffff));
	if(it!=s.begin()){it--;if(it->second>=v) return;it++;}
	
	while(it!=s.end()&&it->second<=v) it=s.erase(it);
	
	s.insert(make_pair(x,v));
}

int query(int x)
{
	set<pair<int,int> >::iterator it=s.upper_bound(make_pair(x,0x7fffffff));
	if(it==s.begin()) return -0x7fffffff;
	it--;
	return it->second;
}

void solve()
{
	int i,j;
	scanf("%d",&n);
	rep(i,n) scanf("%d",&a[i]);
	
	lst.clear();
	rep(i,n) pre[i]=pre[lst[a[i]]]+1,lst[a[i]]=i;

	int mx=0;
	rep(i,n) mx=max(mx,pre[i]);
	
	ans=max(1,mx-32);
	
	rep(i,n)if(pre[i]>=ans) g[i]=a[i]; else g[i]=-0x7fffffff;
	while(1)
	{
		bool flg=0;
		s.clear();
		
		rep(i,n) f[i]=g[i];
		rep(i,n)
		{
			g[i]=-0x7fffffff;
			g[i]=query(a[i]);
			if(g[i]!=-0x7fffffff) flg=1;
			
			if(f[i]!=-0x7fffffff)
			{
				push(a[i]*2-f[i],f[i]);
			}
		}
		
		if(flg) ans++; else break;
	}
	
	printf("%d\n",n-ans);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}