#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 4e5+10;
const ll mod = 998244353;

ll a[mn];
void solve(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	ll ps=0;
	ll mx=0,sm=0;
	for(int i=0;i<n;i++){
		while(a[i]%2==0)a[i]/=2,++ps;
		mx=max(mx,a[i]);
		sm+=a[i];
	}
	sm+=(mx<<ps)-mx;
	printf("%lld\n",sm);
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	
	int tc;
	cin>>tc;
	while(tc--)solve();
}