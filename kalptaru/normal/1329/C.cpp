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
ll mod1=1000000007;
ll mod2=67280421310721;
ll mod3=998244353;
ll mi3=499122177;
ll INF=1e18;
ll po(ll a,ll b)
{
	ll res=1;
//	a=a%mod3;
	while(b>0)
	{
		if(b%2==1)
		{
			res*=a;
//			res%=mod3;
		}
		a*=a;
//		a%=mod3;
		b>>=1;
	}
	return res;
}
ll f(int v,int p,int a[],int d,int g)
{
//	cout<<v<<' ';
	if(a[2*v]==0 && a[2*v+1]==0)
	{
		if(d==g)
		{
//			cout<<'k';
			return p;
		}
		else
		{
			int u=a[v];
			a[v]=0;
			return u;
		}
	}
	if(a[2*v]>a[2*v+1])
	{
		ll o=f(2*v,a[v],a,d+1,g);
		if(o==a[v])
		{
//			cout<<'k';
			return p;
		}
		else
		{
			int u=a[v];
			a[v]=o;
			return u;
		}
	}
	if(a[2*v]<a[2*v+1])
	{
		ll o=f(2*v+1,a[v],a,d+1,g);
		if(o==a[v])
		{
//			cout<<'k';
			return p;
		}
		else
		{
			int u=a[v];
			a[v]=o;
			return u;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int g,h;
		cin>>h>>g;
		ll n=po(2,h);
		int a[2*n]={0};
		FOR(i,1,n)
		{
			cin>>a[i];
		}
//		FOR(i,0,n)
//		{
//			cout<<a[i]<<' ';
//		}
//		cout<<'\n';
		int l=n-po(2,g);
//		cout<<l<<'\n';
		int ans[l];
		ll c=0,o;
		FOR(i,1,n)
		{
			int y=log2(i);
			while(c<l)
			{
				o=f(i,0,a,y+1,g);
//				cout<<"------"<<o<<'\n';
				if(o==0)
				break;
				ans[c]=i;
				c++;
			}
		}
		ll s=0;
		FOR(i,1,n-l)
		{
			s+=a[i];
//			cout<<a[i]<<' ';
		}
		cout<<s<<'\n';
		FOR(i,0,l)
		{
			cout<<ans[i]<<' ';
		}
		cout<<'\n';
	}
	return 0;
}