#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;

ll po(ll a,ll b)
{
	ll re=1;
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
		}
		a=(a*a);
		b>>=1;
	}
	return re;
}
struct point 
{
	long double x=0,y=0;
};
long double dis(point p,point q,point r)
{
	long double ans,a,b,c;
	a=r.y-p.y;
	b=p.x-r.x;
	c=a*r.x+b*r.y;
//	cout<<a<<' '<<b<<' '<<c<<' ';
	ans=abs(a*q.x+b*q.y-c)/sqrt(a*a+b*b);
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		point p[n];
		FOR(i,0,n)
		cin>>p[i].x>>p[i].y;
		cout<<fixed<<setprecision(10);
		long double ans=2*mod,o;
		FOR(i,0,n)
		{
			o=dis(p[i],p[(i+1)%n],p[(i+2)%n]);
//			cout<<o<<'\n';
			ans=min(ans,o/2);
		}
		cout<<ans;
	}
	return 0;
}