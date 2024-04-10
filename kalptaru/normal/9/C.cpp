#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define readarr(a,n) ll a[(n)+2]; FOR(i, 1, (n)+1) {cin >> a[i];}
#define readmat(a,n,m) ll a[(n+2)][(m+2)]; FOR(i, 1, (n)+1){FOR(j,1,(m)+1)cin>>a[i][j];}
#define printarr(a,l,r) FOR(i, l, (r)+1) {cout<< a[i]<<' ';}
#define printmat(a,n,m) FOR(i, 0, (n)){FOR(j,,(m))cout<<a[i][j]<<' ';cout<<"\n";}
#define setpre(n) std::cout << std::fixed << std::setprecision(n);
#define pb(n) push_back((n));
ll b2d(ll a)
{
	ll r=0,j=1;
	while(a>0)
	{
		if(a%2==1)
		r+=j;
		j*=10;
		a=a>>1;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
//	cin>>t;
	while(t--)
	{
		ll ans=0;
		string n;
		cin>>n;
		ll j=1;
		vector<int> an;
		int i=0;
		bool f=0;
		while(i<n.size())
		{
			if(f)
				{an.pb(1);}
			else if(n[i]=='1')
				{an.pb(1);}
			else if(n[i]=='0')
				{
					an.pb(0);
				}
			else
			{
				an.pb(1);
				f=1;
			}
			i++;
		}
		FOR(i,0,an.size())
		{
			if(an[an.size()-i-1]==1)
			ans+=j;
			j=j<<1;
		}
		cout<<ans;
	}
}