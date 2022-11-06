#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
#define spre cout<<fixed<<setprecision(15);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e18;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("INPUT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	#endif
	int test=1;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		string s[n];
		int a[3]={0};
		FOR(i,0,n)
		{
			cin>>s[i];
			FOR(j,0,n)
			{
				if(s[i][j]=='X')
				{
					a[(i+j)%3]++;
				}
			}
		}
		if(a[0]<a[1] && a[0]<a[2])
		{
			FOR(i,0,n)
			{
				FOR(j,0,n)
				{
					if(s[i][j]=='X' && (i+j)%3==0)
					{
						s[i][j]='O';
					}
				}
			}
		}
		else if(a[1]<a[2])
		{
			FOR(i,0,n)
			{
				FOR(j,0,n)
				{
					if(s[i][j]=='X' && (i+j)%3==1)
					{
						s[i][j]='O';
					}
				}
			}
		}
		else
		{
			FOR(i,0,n)
			{
				FOR(j,0,n)
				{
					if(s[i][j]=='X' && (i+j)%3==2)
					{
						s[i][j]='O';
					}
				}
			}
		}
		FOR(i,0,n)
		cout<<s[i]<<'\n';
	}
	return 0;
}