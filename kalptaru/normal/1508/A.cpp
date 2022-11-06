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
#define spre cout<<fixed<<setprecision(1);
typedef long long int ll;
using namespace std;
// ll mod=67280421310721;
// ll mod=8589934592;
const ll mod=1e9+7;
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
typedef unsigned long long uint64;
uint64 xoroshiro128plus(uint64 s[2]) {
  uint64 s0 = s[0];
  uint64 s1 = s[1];
  uint64 result = s0 + s1;
  s1 ^= s0;
  s[0] = ((s0 << 55) | (s0 >> 9)) ^ s1 ^ (s1 << 14);
  s[1] = (s1 << 36) | (s1 >> 28);
  return result;
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
    // ll gtest=0;
	ll test=1;
	cin>>test;
	while(test--)
	{
		int n;
		string a,b,c;
		cin>>n>>a>>b>>c;
		int fa=0,fb=0,fc=0;
		FOR(i,0,2*n)
		{
			if(a[i]=='1')
				fa++;
			if(b[i]=='1')
				fb++;
			if(c[i]=='1')
				fc++;
		}
		bool ca=1,cb=1,cc=1;
		if(fa<n)
		{
			ca=0;
		}
		if(fb<n)
		{
			cb=0;
		}
		if(fc<n)
		{
			cc=0;
		}
		if(ca!=cb)
		{
			if(ca==cc)
			{
				cb=cc;
				b=c;
			}
			else
			{
				ca=cc;
				a=c;
			}
		}
		if(ca)
		{
			int u=0,v=0;
			while(u<2*n || v<2*n)
			{
				if(u==2*n)
				{
					cout<<b[v];
					v++;
				}
				else if(v==2*n)
				{
					cout<<a[u];
					u++;
				}
				else if(a[u]=='1')
				{
					if(b[v]=='1')
					{
						cout<<1;
						u++;
						v++;
					}
					else
					{
						cout<<0;
						v++;
					}
				}
				else
				{

					if(b[v]=='1')
					{
						cout<<0;
						u++;
					}
					else
					{
						cout<<0;
						u++;
						v++;
					}
				}
			}
		
		}
		else
		{
			int u=0,v=0;
			while(u<2*n || v<2*n)
			{
				if(u==2*n)
				{
					cout<<b[v];
					v++;
				}
				else if(v==2*n)
				{
					cout<<a[u];
					u++;
				}
				else if(a[u]=='1')
				{
					if(b[v]=='1')
					{
						cout<<1;
						u++;
						v++;
					}
					else
					{
						cout<<1;
						u++;
					}
				}
				else
				{

					if(b[v]=='1')
					{
						cout<<1;
						v++;
					}
					else
					{
						cout<<0;
						u++;
						v++;
					}
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}