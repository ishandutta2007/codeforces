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
	int t;
	cin>>t;
	while(t--)
	
	{
	int b,p,f,h,c,ans=0;
	cin>>b>>p>>f>>h>>c;
	b=b>>1;
	if(h>c)
	{
		ans+=min(b,p)*h;
		b-=min(b,p);
		ans+=min(b,f)*c;
	}
	else
	{
		ans+=min(b,f)*c;
		b-=min(b,f);
		ans+=min(b,p)*h;
	}
	cout<<ans<<"\n";
	}
}