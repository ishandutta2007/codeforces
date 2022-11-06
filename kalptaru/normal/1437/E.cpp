#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e9;
ll po(ll a,ll b){
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
ll t[4000000];
map<ll,int> m;
void update(int v,int tl,int tr,int p,int val)
{
	if(tl==tr)
	{
		t[v]=val;
		return;
	}
	int tm=(tl+tr)/2;
	if(p>tm)
	{
		update(2*v+1,tm+1,tr,p,val);
	}
	else
	{
		update(2*v,tl,tm,p,val);
	}
	t[v]=max(t[2*v],t[2*v+1]);
	return ;
}
ll ma(int v,int tl,int tr,int l,int r)
{
	if(l>r)
	{
		return -INF;
	}
	if(tl==l && tr==r)
	{
		return t[v];
	}
	int tm=(tl+tr)/2;
	return max( ma(2*v,tl,tm,l,min(tm,r)), ma(2*v+1,tm+1,tr,max(l,tm+1),r));
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	// cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		ll a[n];
		FOR(i,0,1000000)
		{
			t[i]=-INF;
		}
		vector<ll> d;
		FOR(i,0,n)
		{
			cin>>a[i];
			a[i]-=i;
			if(m[a[i]]==0)
			{
				d.pb(a[i]);
				m[a[i]]=1;
			}
		}
		sort(d.begin(),d.end());
		d.pb(-INF);
		int s=d.size();
		FOR(i,0,s)
		{
			m[d[i]]=i;
		}
		int b[k];
		FOR(i,0,k)
		{
			cin>>b[i];
		}
		FOR(i,1,k)
		{
			if(a[b[i]-1]<a[b[i-1]-1])
			{
				cout<<-1;
				return 0;
			}
		}
		update(1,0,s-1,0,0);
		int j=0,o=0,f=0;
		if(k>0 && b[0]==1)
		{
			update(1,0,s-1,0,-INF);
			update(1,0,s-1,m[a[0]],1);
			j=f=1;
		}
		ll q;
		FOR(i,f,n)
		{
			q=ma(1,0,s-1,0,m[a[i]]);
			// cout<<q<<' '<<a[i]<<'\n';

			if(j<k && b[j]==(i+1))
			{
				// cout<<i<<'\n';
				update(1,0,s-1,0,-INF);
				while(o<i)
				{
					update(1,0,s-1,m[a[o]],-INF);
					o++;
				}
				j++;
			}
			update(1,0,s-1,m[a[i]],q+1);
		}
		q=ma(1,0,s-1,0,s-1);
		if(q<0)
		{
			cout<<-1;
		}
		else
		{
			cout<<n-q;
		}
	}
	return 0;
}