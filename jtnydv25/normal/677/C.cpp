#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ui unsigned int
#define ull unsigned ll
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define si set<int>
#define sll set<ll>
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define mii map<int,int>
#define mll map<ll,ll>
#define vvi vector<vi >
#define vvl vector<vll >
#define cps CLOCKS_PER_SEC
int times[64];
const int mod = 1e9+7;
int main()
{
	memset(times,0,sizeof times);
	for(int i = 0;i<64;i++)
		for(int j = 0;j<64;j++)
			times[i&j]++;
	string s;
	cin>>s;
	ll ans = 1;
	for(int i = 0;i<s.length();i++)
	{
		int n;
		int x = (int)s[i];
		if(x>=48 && x<=57)
			n = x-48;
		if(x>=65 && x <= 90)
			n = x-65 + 10;
		if(x>=97 && x<= 122)
			n = x - 97 + 36;
		if(x == 95)
			n = 63;
		if(x == 45)
			n = 62;
		// cout<<n<<endl;
		ans = (ans*times[n])%mod;
	}	
	cout<<ans;
}