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
ll INF=1e9;
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
	return re;}
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
		int t[n];
		FOR(i,0,n)
		{
			cin>>t[i];
		}
		int cnt[n+2]={0};
		cnt[0]=1;
		int i=1,j=0;
		while(i<n)
		{
			while(i<n && cnt[j]>0)
			{
				cnt[j]--;
				i++;
				cnt[j+1]++;
				while(i<n && t[i]>t[i-1])
				{
					cnt[j+1]++;
					i++;
				}
			}
			j++;
		}
		cout<<j<<'\n';
	}
	return 0;
}