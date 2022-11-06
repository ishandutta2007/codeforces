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
		int n,m;
		ll ans=1,r=1000000007;
		cin>>n>>m;
		bool f[m][26];
		int c[m];
		FOR(i,0,m)
		{
			c[i]=0;
			FOR(j,0,26)
			f[i][j]=0;
		}
		FOR(i,0,n)
		{
			string s;
			cin>>s;
			FOR(j,0,m)
			{
				if(f[j][s[j]-'A']==0)
				c[j]++;
				f[j][s[j]-'A']=1;
			}
		}
		FOR(i,0,m)
		{
			ans=(ans*c[i])%r;
		}
		cout<<ans;
	}
}