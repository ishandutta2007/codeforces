#include <bits/stdc++.h>
#include <string>
#include <cmath>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i > (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll t=1;
//	cin>>t;
	while(t--)
	{
			int n,m;
			cin>>n>>m;
			int l=n/2+n%2,r=n;
			FOR(i,l,r+1)
			{
				if(i%m==0)
				{
					cout<<i;
					return 0;
				}
			}
			cout<<-1;
	}
	return 0;
}