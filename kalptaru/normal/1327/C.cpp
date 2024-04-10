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
		int n,m,k;
		cin>>n>>m>>k;
		pair<int,int> s[k],f[k];
		FOR(i,0,k)
		{
			cin>>s[i].first>>s[i].second;
		}
		FOR(i,0,k)
		{
			cin>>f[i].first>>f[i].second;
		}
		cout<<n+m+n*m-3<<'\n';
		FOR(i,1,n)
		cout<<"U";
		FOR(i,1,m)
		cout<<"L";
		FOR(i,1,m)
		cout<<"R";
		FOR(i,1,n)
		{
			cout<<"D";
			FOR(j,1,m)
			{
				if(i%2==1)
				{
					cout<<"L";
				}
				else
				{
					cout<<"R";
				}
			}
		}
	}
	return 0;
}