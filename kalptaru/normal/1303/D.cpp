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
ll m1=1000000007;
ll m2=67280421310721;
ll po(ll a,ll b)
{
	ll res=1;
	a=a%m1;
	while(b)
	{
		if(b%2==1)
		res=((res*a)%m1);
		a=((a*a)%m1);
		b>>=1;
	}
	return res;
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
		ll n,m;
		cin>>n>>m;
		ll a[m];
		ll c[50]={0};
		ll s=0;
		int mk=0;
		FOR(i,0,m)
		{
			cin>>a[i];
			if(s<n)
			s+=a[i];
			int k=log2(a[i]);
			mk=max(mk,k);
			c[k]++;
		}
		if(s<n)
		{
			cout<<-1<<'\n';
			continue;
		}
		ll nb[100]={0};
		int y=-1;
		while(n>0)
		{
			y++;
			if(n%2==1)
			{
				nb[y]=1;
			}
			n>>=1;
		}
		ll ans=0;
		FOR(i,0,49)
		{
//			cout<<nb[i]<<' ';
			if(c[i]<nb[i])
			{
				int u=i;
				while(c[u]==0)
				{
					c[u]=1;
					ans++;
					u++;
				}
				c[u]--;
			}
			else if(c[i]>nb[i])
			{
				c[i+1]+=((c[i]-nb[i])>>1);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}