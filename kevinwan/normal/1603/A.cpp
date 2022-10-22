#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
const double PI = acos(-1.L);
const int mn = 3e5+10;
const ll mod = 1e9+7;
ll a[mn];
ll gcd(ll a, ll b){
	while(b)a%=b,swap(a,b);
	return a;
}
void solve(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	ll lcm=1;
	bool flag=1;
	for(int i=1;i<=n;i++){
		lcm = lcm/gcd(lcm,i+1)*(i+1);
		if(lcm>1e10)lcm=1e10;
		if(a[i]%lcm==0)flag=0;
	}
	printf("%s\n", flag ? "YES" : "NO");
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(0);
	int tc;
	cin>>tc;
	while(tc--){
		solve();
	}
}