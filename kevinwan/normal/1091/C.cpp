#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const ll mod = 998244353;
const int mn = 1005;
set<ll> ans;
ll geta(ll n, ll k) {
	return (n / k)*(n / k - 1)*k/2 + n/k;
}
int main() {
	ll n;
	scanf("%lld", &n);
	for (ll i = 1; i*i <= n; i++) {
		if (n%i == 0) {
			ans.insert(geta(n, i));
			ans.insert(geta(n, n / i));
		}
	}
	for (auto num : ans) printf("%lld ", num);
}