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
#define spre cout<<fixed<<setprecision(10);
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=985661441;
ll INF=1e18;
ll po(ll a,ll b){
	ll re=1;  
	while(b)
	{
		if(b%2==1)
		{
			re=(re*a);
			re%=mod;
		}
		a=(a*a);
		a%=mod;
		b>>=1;
	}
	return re;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif	
	ll test=1;
	cin>>test;
	while(test--)
	{
		int n,m;
		cin>>n>>m;
		string s[n];
		FOR(i,0,n)
		{
			cin>>s[i];
		}
		int o=0;
		if(n%3==0)
		{
			o=1;
		}
		bool f;
		FOR(i,o,n)
		{
			f=1;
			FOR(j,0,m)
			{
				s[i][j]='X';
				if(i<(n-2))
				{
					if(s[i+1][j]=='X' && f)
					{
						s[i+2][j]='X';
						f=0;
					}
					else if(f && s[i+2][j]=='X')
					{
						s[i+1][j]='X';
						f=0;
					}
				}
			}
			if(f && i<(n-2))
			{
				s[i+1][0]='X';
				s[i+2][0]='X';
			}
			i+=2;
		}
		FOR(i,0,n)
		{
			cout<<s[i]<<'\n';
		}



	}
	return 0;
}