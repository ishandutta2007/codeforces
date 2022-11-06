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
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
//	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		ll a[n],s=0,ps=0,ma=0,mi=INF;
		FOR(i,0,n)
		{
			cin>>a[i];
			s+=a[i];
			ma=max(ma,a[i]);
			
		}
		sort(a,a+n);
		ll m,ans=INF;
		int co=0;
		int pre=a[0];
		FOR(i,0,n)
		{
			ps+=a[i];
			if(a[i]==pre)
			{
				co++;
			}
			else
			{
				if(co>=k)
				{
					ans=0;
					break;
				}
				co=1;
				pre=a[i];
			}
			if((i+1)>=k)
			{
				m=k*a[i]+(i+1-k)*(a[i]-1)-ps;
//				cout<<i<<'p'<<m<<'\n';
				if(m>=0)
				ans=min(ans,m);
			}
			else
			{
				m=(i+1)*a[i]-ps+s-(n-k)*(a[i]+1)-(k-i)*a[i];
				if(m>=0)
				ans=min(ans,m);
			}
			if((n-i)>=k)
			{
				m=s-k*a[i]-(n-i-k)*(a[i]+1);
//				cout<<i<<'s'<<m<<'\n';
				if(m>=0)
				ans=min(ans,m);
			}
			else
			{
				m=s-(n-i)*a[i]+(n-k)*(a[i]-1)+(i+k-n+1)*a[i]-ps;
				if(m>=0)
				ans=min(ans,m);
			}
			s-=a[i];
		}
		cout<<ans<<'\n';
	}
	return 0;
}