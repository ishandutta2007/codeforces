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
int c[100005][26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int v;
		FOR(i,0,n)
		{
			v=i%k;
			c[min((k-v-1),v)][s[i]-'a']++;
		}
		int ans=0;
		FOR(i,0,(k/2)+4)
		{
			int m=0;
			FOR(j,0,26)
			{
				m=max(c[i][j],m);
//				cout<<c[i][j]<<' ';
				c[i][j]=0;
			}
//			cout<<'\n';
			ans+=m;
		}
		cout<<n-ans<<'\n';
	}
	return 0;
}