#include "bits/stdc++.h"

#ifdef PRINTERS
#include "printers.hpp"
using namespace printers;
#define tr(a)		cerr<<#a<<" : "<<a<<endl
#else
#define tr(a)    
#endif
#define	int 		long long
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>	
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n;
map<int,int>mp;
vi a;
	
void solve()
{
	cin>>n;
	a.resize(n);
	rep(i,0,n)
		cin>>a[i];
	long double ans=0,sum=0;
	for(int i=n-1;i>=0;i--)
	{
		sum+=a[i];
		ans+=sum-(n-i)*a[i]-mp[a[i]+1]+mp[a[i]-1];
		mp[a[i]]++;
	}
	cout<<fixed<<setprecision(0);
	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--)
		solve();
	return 0;
}