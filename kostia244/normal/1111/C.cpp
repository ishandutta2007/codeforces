#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, k, A, B, a, cls = 0;
vector<ll> v;

ll cnt(int s, int e) {
	return  max((ll)(lower_bound(v.begin(), v.end(), e + 1) - upper_bound(v.begin(), v.end(), s - 1)), 0ll);
}

long long f(ll s, ll e) {
	if(cls > 100000000)
		exit(1);
	cls++;
	if(s == e)
		return cnt(s, s) ? B * cnt(s, s) : A;
	ll sum = 0;
	ll mid = (s + e) / 2;
	sum = cnt(s, e);
	ll c, l, r;
	c = (sum ? (B *  (e - s + 1) * sum) : A);
	l = f(s, mid);
	if(sum == 0)
		return A;
	if(l > c)
		return c;
	r = f(mid + 1, e);
	return min(c, l + r);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k >> A >> B;
	while(k--) {
		cin >> a;
		v.pb(a);
	}
	sort(v.begin(), v.end());
	printf("%lld", f(1, 1 << n));
}