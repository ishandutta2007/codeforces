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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		bool g=0;
		ll a[n],b[n];
		FOR(i,0,n)cin>>a[i];
		FOR(i,0,n)cin>>b[i];
		ll l=0,r=b[0];
		while(l<=r)
		{
			bool f=0;
//			cout<<"\nc"<<l<<' '<<r<<'\n';
			ll mid=(l+r)/2;
			ll o=mid;
			FOR(i,0,n)
			{
//				cout<<o<<' ';
				if(o>b[i])
				{
					f=1;
					break;
				}
				o=a[(i+1)%n]-b[i]+o;
				if(o<0)
				o=0;
			}
			if(l==r && (f || o>mid))
			break;
			if(f)
			{
				r=mid;
			}
			else if(o>mid)
			{
				l=mid+1;
			}
			else
			{
				g=1;
				break;
			}
		}
//		cout<<"-------";
		if(g)
		cout<<"YES\n";
		else
		cout<<"NO\n";
	}
	return 0;
}