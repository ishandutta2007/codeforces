#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define all(a) a.begin(),a.end()
#define sz(a) (ll)(a.size())
const ll M=2e5+5;
ll a[M];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	ll s=0;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		s=s+a[i];
	}
	sort(a+1,a+1+n);
	if(s<m)
	{
		cout << -1;
		return 0;
	}
	ll l=1,r=n,p=-1;
	while(l<r)
	{
		ll mid=(l+r)/2;
		if(mid==p)
			mid++;
		p=mid;
		ll s=0;
		ll curr=0;
		ll x=0;
		for(ll i=n;i>=1;i--)
		{
			if(curr==mid)
			{
				curr=0;
				x++;
			}
			s=s+max(a[i]-x,(ll)0);
			curr++;
		}
		if(s>=m)
			r=mid;
		else
			l=mid+1;
	}
	cout << r;
	return 0;
}