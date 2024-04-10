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

int main()
{
	int n,h,a[1005];
	cin>>n>>h;
	
	int ans = 0;
	for(int i = 0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]>h)
			ans++;
	}
	cout<<ans+n;
	return 0;
}