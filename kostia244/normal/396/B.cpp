#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1e6, mod = 1e9 + 7;
int _prime(int x) {	
	if(x == 1) return 0;
	int ok = 1;
	for(int d = 2; d*d <= x; d++) {
		if(x%d == 0) return 0;
	}
	return 1;
}
vector<int> primes;
int prime(int a) {
	for(auto i : primes) if(a != i && a%i == 0) return 0;
	return 1;
}
array<ll, 2> frac;
array<ll, 2> add(array<ll, 2> a, array<ll, 2> b) {
	ll x = a[0]*b[1] + b[0]*a[1];
	ll y = a[1]*b[1];
	ll g= __gcd(x, y);
	return {x/g, y/g};
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 2; i <= 35000; i++) {
		if(_prime(i)) primes.push_back(i);
	}
	int t;
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		if(n==2) {cout << "1/6\n"; continue;}
		ll lo = n;
		while(!prime(lo)) lo--;
		ll hi = n+1;
		while(!prime(hi)) hi++;
		array<ll, 2> cur = {lo*(hi-2) - 2*(hi-n-1), 2ll*lo*hi};
		cur = add(cur, {0, 1});
		cout << cur[0] << "/" << cur[1] << endl;
	}
}