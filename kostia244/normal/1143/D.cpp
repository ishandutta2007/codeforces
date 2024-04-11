#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mod 998244353ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
}
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <int> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, k, mn = LONG_LONG_MAX, mx = INT_MIN, a, b;
int main() {
	doin();
	cin >> n >> k >> a >> b;
	//k-a-b |a-b|
	int p[4] = {a+b, (k-a)+b, a+(k-b), (k-a)+(k-b)};
	for(int i = 1; i <= (n/2); i++)
		for(int j = 0; j < 4; j++){
			ll t = (i-1)*1ll*k + p[j];
			t= ((n*k)/__gcd(t,n*k));
			mn = min(mn, t);
			mx = max(mx, t);
		}
	ll t = abs(a-b);
//	if(t) {
	t= ((n*k)/__gcd(t,n*k));
	mn = min(mn, t);
	mx = max(mx, t);
//	}
	t = k-a-b;
//	if(t) {
	t= ((n*k)/__gcd(t,n*k));
	mn = min(mn, t);
	mx = max(mx, t);
//	}
	cout << fixed << mn << " " << mx;
}