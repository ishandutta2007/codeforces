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
bool che(pt i,pt j,pt c)
{
	if(min(i.x,j.x)>c.x)
	return 0;
	if(min(i.y,j.y)>c.y)
	return 0;
	if(min(i.z,j.z)>c.z)
	return 0;
	if(max(i.x,j.x)<c.x)
	return 0;
	if(max(i.y,j.y)<c.y)
	return 0;
	if(max(i.z,j.z)<c.z)
	return 0;
	return 1;
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
		vector<pt> b;
		pt a;
		int p,q;
		FOR(i,0,n)
		{
			cin>>a.x>>a.y>>a.z;
			a.i=i+1;
			b.pb(a);
		}
		FOR(i,0,n)
		{
			if(f[i]==0)
			{
				p=i;
				q=i+1;
				while(f[q])
				q++;
				FOR(j,i+2,n)
				{
					if(f[j]==0 && che(b[p],b[q],b[j]))
					q=j;
				}
				cout<<p+1<<' '<<q+1<<'\n';
				f[q]=1;
				f[p]=1;
			}
		}
	}
	return 0;
}
//min(a[p].x,a[q].x)<=a[i].<=max(xa,xb) , min(ya,yb)=yc=max(ya,yb), and min(za,zb)=zc=max(za,zb)