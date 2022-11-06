#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
bool f[50005];
struct pt
{
	ll x,y,z,i;
};
bool che(pt i,pt j)
{
	if(i.x<j.x)
	return 1;
	if(i.x==j.x)
	{
		if(i.y<j.y)
		return 1;
		if(i.y==j.y)
		{
			if(i.z<j.z)
			return 1;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while ( t-- ) 
	{
		int n;
		cin>>n;
		vector<pt> b,c;
		pt a;
		FOR(i,0,n)
		{
			cin>>a.x>>a.y>>a.z;
			a.i=i+1;
			b.pb(a);
		}
		sort(b.begin(),b.end(),che);
		pt p,q;
		bool f[n+1]={0};
		FOR(i,0,n-1)
		{
			if(f[b[i].i]==0 && f[b[i+1].i]==0)
			{
				p=b[i];
				q=b[i+1];
				if(q.x==p.x && q.y==p.y)
				{
					cout<<p.i<<' '<<q.i<<'\n';
					f[p.i]=1;
					f[q.i]=1;
				}
			}
		}
		FOR(i,0,n)
		{
			if(f[b[i].i]==0)
			c.pb(b[i]);
		}
		b=c;
		c.clear();
		n=b.size();
		FOR(i,0,n-1)
		{
			if(f[b[i].i]==0 && f[b[i+1].i]==0)
			{
				p=b[i];
				q=b[i+1];
				if(q.x==p.x)
				{
					cout<<p.i<<' '<<q.i<<'\n';
					f[p.i]=1;
					f[q.i]=1;
				}
			}
		}
		FOR(i,0,n)
		{
			if(f[b[i].i]==0)
			c.pb(b[i]);
		}
		b=c;
		c.clear();
		n=b.size();
		FOR(i,0,n-1)
		{
			if(f[b[i].i]==0 && f[b[i+1].i]==0)
			{
				p=b[i];
				q=b[i+1];
				cout<<p.i<<' '<<q.i<<'\n';
				f[p.i]=1;
				f[q.i]=1;
			}
		}
	}
	return 0;
}
//min(a[p].x,a[q].x)<=a[i].<=max(xa,xb) , min(ya,yb)=yc=max(ya,yb), and min(za,zb)=zc=max(za,zb)