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
		int n,d,tem;
		ll ans=0;
		cin>>d>>n;
		FOR(i,1,n)
		{
			cin>>tem;
			ans+=d-tem;
		}
		cin>>tem;
		cout<<ans;
	}
}