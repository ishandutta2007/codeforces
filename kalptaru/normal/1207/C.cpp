#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define pb(a) push_back(a);
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t=1;
	cin>>t;
	while ( t-- ) 
	{
		ll n,a,b;
		cin>>n>>a>>b;
		string s;
		cin>>s;
		ll m=(2*a/b)+1;
		ll p=n+1,l=n;
		int c=0;
		bool f=1,d=1;
		FOR(i,0,n)
		{
			if(f)
			{
				if(s[i]=='1')
				{
					l++;
					p++;
					f=0;
				}
			}
			else
			{
				if(d)
				{
					if(s[i]=='0')
					{
						c++;
						p++;
						d=0;
					}
					else
					{
						p++;
					}
				}
				else
				{
					if(s[i]=='0')
					{
						c++;
					}
					else
					{
						if(c>m)
						{
							l+=2;
							d=1;
							p++;
						}
						else
						{
							p+=c;
							d=1;
						}
						c=0;
					}
				}
			}
		}
		if(f==0)
		l++;
		cout<<p*b+a*l<<'\n';
//		cout<<p<<' '<<l<<' '<<m;
	}
	return 0;
}