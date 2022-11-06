#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
ll gcd(ll a,ll b)
{
	if(a<b)
	swap(a,b);
	if(a%b==0)return b;
	return gcd(b,a%b);
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
		ll n,p,w,d,x,y,z,g,l;
		cin>>n>>p>>w>>d;
		g=gcd(w,d);
		x=p/w;
		if(p%g!=0 || x>n)
		{cout<<-1<<'\n';return 0;}
		y=0;
		l=p%w;
		FOR(i,0,w)
		{
//			cout<<x<<' '<<y<<' '<<l<<'\n';
			if(l==0 && x+y<=n && x>=0 && y>=0)
			{
				cout<<x<<' '<<y<<' '<<n-x-y;
				return 0;
			}
			if(l>0)
			{
				l-=d;
				y++;
			}
			else
			{
				l+=w;
				x--;
				i--;
			}
		}
		cout<<-1;
	}
	return 0;
}