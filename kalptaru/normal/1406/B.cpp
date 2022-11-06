#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include <sstream>
//#include <unordered_map>
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a-1); i >= (b); i--)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
typedef long long int ll;
using namespace std;
ll mod=1000000007;
//ll mod=67280421310721;
// ll mod=998244353;
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
		ll a[n];
		FOR(i,0,n)
		cin>>a[i];
		sort(a,a+n);
		cout<<max(a[0]*a[1]*a[2]*a[3]*a[n-1],max(a[0]*a[1]*a[n-1]*a[n-2]*a[n-3],a[n-1]*a[n-2]*a[n-3]*a[n-4]*a[n-5]))<<'\n';
	}
	return 0;
}