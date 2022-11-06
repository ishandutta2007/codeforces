#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
#include <unordered_map>
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for(ll i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
//ll mod=67280421310721;
// ll mod=998244353;
ll mod=1000000007;
ll INF=1e18;

ll po(ll a,ll b)
{
	ll re=1;
	a%=mod;
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
	int test=1;
	cin>>test;
	while(test--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		vector<int> seg;
		int o=0,p=0,w=0;
		FOR(i,0,n)
		{
			if(s[i]=='W')
			{
				w++;
				if(i==0 || s[i-1]=='L')
				{
					if(p>0)
					{
						seg.pb(o);
					}
					o=0;
					p++;
				}
				else
				{
					p+=2;
				}
			}
			else
			{
				o++;
			}
		}
		if(w==0)
		{
			cout<<max(0,2*k-1)<<'\n';
			continue;
		}
		sort(seg.begin(),seg.end());
		FOR(i,0,seg.size())
		{
			if(k>=seg[i])
			{
				p++;
				p+=2*seg[i];
				k-=seg[i];
			}
			else
			{
				break;
			}
		}
		p+=2*k;
		cout<<min(2*n-1,p)<<'\n';
	}
	return 0;
}