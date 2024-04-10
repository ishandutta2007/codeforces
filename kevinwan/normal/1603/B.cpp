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
	ll a,b;
	cin>>a>>b;
	if(a>b){
		printf("%lld\n",a+b);
	}
	else{
		printf("%lld\n",b-(b%a)/2);
	}
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