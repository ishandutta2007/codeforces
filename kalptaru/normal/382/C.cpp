#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(a) push_back(a);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,c=0;
		cin>>n;
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		sort(a,a+n);
		if(n==1)
		{
			cout<<-1;
		}
		else if(n==2)
		{
			if(a[0]==a[1])
			cout<<1<<"\n"<<a[0];
			else
			{
				if((a[1]-a[0])%2==0)
				{
					cout<<3<<"\n"<<2*a[0]-a[1]<<' '<<((a[0]+a[1])>>1)<<' '<<2*a[1]-a[0];
				}
				else
				{
					cout<<2<<"\n"<<2*a[0]-a[1]<<' '<<2*a[1]-a[0];
				}
			}
		}
		else
		{
			bool at=1,b=0;
			int v;
			ll d=min(a[1]-a[0],a[2]-a[1]);
			FOR(i,1,n)
			{
				if((a[i]-a[i-1])!=d)
				{
					b=1;
					if(at && (a[i]-a[i-1])==(2*d))
					{
						at=0;
						v=a[i]-d;
					}
					else
					{
						cout<<0;
						return 0;
					}
				}
			}
			if(b)
			{
				cout<<1<<"\n"<<v;
			}
			else
			{
				if(d==0)
				{
					cout<<1<<"\n"<<a[0];
				}
				else
				cout<<2<<"\n"<<a[0]-d<<' '<<a[n-1]+d;
			}
		}
	}
}