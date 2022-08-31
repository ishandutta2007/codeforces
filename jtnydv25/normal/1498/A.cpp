#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

bool good(ll n){
	ll ret = 0;
	ll N = n;
	while(n){
		ret += n % 10;
		n /= 10;
	}
	return __gcd(N, ret) > 1;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		ll n; cin >> n;
		while(!good(n)) n++;
		cout << n << endl;
	}
}