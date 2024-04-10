#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define ff first
#define ss second
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
//ll mod=998244353;
ll INF=1e18;
ll po(ll a,ll b)
{
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
	int test=1;
//	cin>>test;
	while(test--)
	{
		ll n;
		cin>>n;
		int cnt[100005]={0},f=0,to=0,a;
		FOR(i,0,n)
		{
			cin>>a;
			cnt[a]++;
			if(cnt[a]%2==0)
			{
				to++;
			}
			if(cnt[a]==4)
			f++;
		}
		int q;
		cin>>q;
		char t;
		FOR(i,0,q)
		{
			cin>>t>>a;
			if(t=='-')
			
			{
				cnt[a]--;
				if(cnt[a]==3)
				f--;
				if(cnt[a]%2==1)
				to--;
			}
			else
			{
				cnt[a]++;
				if(cnt[a]==4)
				f++;
				if(cnt[a]%2==0)
				to++;
			}
//			cout<<f<<' '<<to<<'\n';
				if(f>0 && to>3)
				cout<<"YES\n";
				else
				cout<<"NO\n";
		}
		
	}
	return 0;
}