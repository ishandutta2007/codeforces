#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
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

string ans(string s)
{
	int len = s.length();
	ll x = 0,y=stoll(s);
	ll pw10 = 10;
	for(int i = 1;i<len;i++)
	{
		x+=pw10;pw10*=10;
	}
	ll mn = max(0LL,(1989+x-y)/pw10);
	while(mn*pw10+y < 1989+x)
		mn++;
	return to_string(mn*pw10+y);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		string s1 = s.substr(4,s.length()-4);
		cout<<ans(s1)<<endl;
	}
}