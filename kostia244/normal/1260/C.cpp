//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool bruteforce(ll a, ll b, ll k) {
	ll cnt = 1, ans = 1, lst = -1;
	for(int g = __gcd(a, b), i = 0; i <= a*b; i+=g) {
		if(i%a==0&&i%b==0) {
			cnt = 1;
			lst  = -1;
		} else if(i%a==0) {
			if(lst==0) cnt++;
			else cnt = 1;
			lst = 0;
		} else if(i%b==0) {
			if(lst==1) cnt++;
			else cnt = 1;
			lst = 1;
		}
		ans = max(ans, cnt);
	}
	return ans<k;
}
void solve() {
	ll a, b, k;
	cin >> a >> b >> k;
//	a = rng()%100 +1, b = rng()%100 + 1, k = rng()%100 + 1;
	if(a>b) swap(a, b);
	ll t;
	t = 1+ (b-1-__gcd(a, b) )/a;

//	if((t<k)!=bruteforce(a, b, k)) {
//		cout << a << " " << b << " " << k << "WA\n";
		cout << (t<k?"OBEY":"REBEL") << "\n";
//	}
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
//	n = 1000;
	cin >> n;
	while(n--) solve();
}