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
		int n;
		cin>>n;
		int ans=0,s=0;
		int x,c[101]={0};
		FOR(i,0,n)
		{
			cin>>x;
			c[x]++;
		}
		FOR(i,0,101)
		{
			s+=c[i];
			while(ans*(i+1)<s)
			ans++;
		}
		cout<<ans;
	}
}