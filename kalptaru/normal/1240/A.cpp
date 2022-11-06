#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int cnt[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		int n,x,y,a,b;
		cin>>n;
		int ans=-1;
		ll p[n],k,m=0;
		FOR(i,0,n)
		cin>>p[i];
		sort(p,p+n,greater<ll> ());
		cin>>x>>a>>y>>b>>k;
		if(x<y)
		{
			swap(a,b);
			swap(x,y);
		}
		int pb=0,px=0,py=0;
		FOR(i,1,n+1)
		{
			if(i%a==0)
			{
				if(i%b==0)
				{
					m+=((p[pb]/100)*y);
					m+=((p[pb+px]/100)*(x-y));
					m+=((p[pb+px+py]/100)*y);
					pb++;
//					cout<<pb<<' '<<px<<' '<<py;
				}
				else
				{
					m+=((p[pb+px]/100)*(x-y));
					m+=((p[pb+px+py]/100)*y);
					px++;
				}
			}
			else if(i%b==0)
			{
				m+=((p[pb+px+py]/100)*y);
				py++;
			}
			if(m>=k)
			{
				ans=i;
				break;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}