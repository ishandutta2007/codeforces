#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n,p,tem,l=1,r;
		ll ans=0;
		cin>>n>>p;
		string s;
		cin>>s;
		if(p>n/2)
		p=n-p+1;
		r=p;
		bool f=1;
		FOR(i,0,p-1)
		{
			tem=abs(s[i]-s[n-1-i]);
			ans+=min(tem,26-tem);
			if(tem==0 && f)
			{
				l++;
			}
			else
			f=0;
		}
		tem=abs(s[p-1]-s[n-p]);
		ans+=min(tem,26-tem);
		FOR(i,p,n/2)
		{
			tem=abs(s[i]-s[n-1-i]);
			ans+=min(tem,26-tem);
			if(tem!=0)
			{
				r=i+1;
			}
		}
//		cout<<p<<' '<<l<<' '<<r<<' ';
		ans+=(r-l);
		ans+=min(r-p,p-l);
		cout<<ans;
	}
}