#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
//const ll mod = 1e9 + 7;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	ll n, t, k, d;
	cin >> n >> t >> k >> d;
	ll a1 = t* ((n+k-1)/k);
	ll a2 = LLONG_MAX;
	for(int i = 0; i <= n; i++)
		a2 = min(a2, max(t* ((i+k-1)/k), d + t* (((n-i)+k-1)/k)));
	if(a2>=a1) {
		cout << "NO";
	} else{
		cout << "YES";
	}
}