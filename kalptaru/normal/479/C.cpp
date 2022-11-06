#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+1]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,,(m))cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(n) push_back((n));
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector< pair<ll,ll> > arr;
		ll a,b,c,pm=0;
		FOR(i,0,n)
		{
			cin>>a>>b;
			arr.pb(make_pair(a,b));	
		}
		sort(arr.begin(),arr.end());
		a=arr[0].second,b=arr[0].second,c=arr[0].first;
		FOR(i,0,n)
		{
			if(c==arr[i].first)
			{
				a=min(a,arr[i].second);
				b=max(a,arr[i].second);
				
			}
			else
			{
				if(pm<=a)
				pm=b;
				else
				pm=c;
				c=arr[i].first;
				a=arr[i].second;
				b=a;
			}
		}
		if(pm<=a)
		cout<<b;
		else
		cout<<c;
	}
}