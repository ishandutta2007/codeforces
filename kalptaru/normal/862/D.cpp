#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
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
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int pos1,pos0;
void fi(int l,int r,int pr,int x,int n)
{
	if(r<l)
	return;
	cout<<"? ";
	int y,mid;
	FOR(i,0,n)
	{
		if((i>=l)&&i<=r)
		cout<<'0';
		else
		cout<<'1';
	}
	cout<<'\n';
	cin>>y;
	y=(r-l+1+x-y)/2;
	if(y==0)
	{
		pos1=l+1;
		l=r+1;
		r=pr;
		mid=(l+r)/2;
	}
	else if(y==(r-l+1))
	{
		pos0=l+1;
		l=r+1;
		r=pr;
		mid=(l+r)/2;
	}
	mid=(l+r)/2;
	if(pos1!=0 && pos0!=0)
	return;
	fi(l,mid,r,x,n);
}
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,x;
		cin>>n;
		cout<<"? ";
		FOR(i,0,n)
		cout<<'1';
		cout<<'\n';
		cin>>x;
		fi(0,n/2,n-1,x,n);
		cout<<"! "<<pos0<<' '<<pos1;
	}
	return 0;
}