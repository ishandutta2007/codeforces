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
ll mod=1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test=1;
	cin>>test;
	while(test--)
	{
		string s,t;
		cin>>s>>t;
		int n=s.size();
		int fo[n+1][26];
		FOR(i,0,26)
		fo[n][i]=-1;
		FOR(i,0,n)
		{
			FOR(j,0,26)
			{
				fo[n-i-1][j]=fo[n-i][j];
			}
			fo[n-i-1][s[n-i-1]-'a']=n-i;
		}
		int ans=1,o=0;
		FOR(i,0,t.size())
		{
			if(fo[0][t[i]-'a']==-1)
			{
				ans=-1;
				break;
			}
			if(fo[o][t[i]-'a']==-1)
			{
				ans++;
				o=0;
				i--;
			}
			else
			{
				o=fo[o][t[i]-'a'];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}