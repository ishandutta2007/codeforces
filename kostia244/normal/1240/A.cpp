#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

struct solver {
	ll n, k, x, y, a, b;
	vi p;
	void read() {
		cin >> n;
		p.assign(n, 0);
		for (auto &i : p)
			cin >> i, i /= 100;
		sort(all(p), greater<ll>());
		cin >> x >> a >> y >> b >> k;
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}
	}
	bool check(ll N) {
		ll sab = N / (a * b / __gcd(a, b));
		ll sa = N / a;
		ll sb = N / b;
		ll i = 0, sum = 0;
		for (int j = 0; i < n && j < sab; i++, j++)
			sum += p[i] * (x + y);
		for (int j = sab; i < n && j < sa; i++, j++)
			sum += p[i] * x;
		for (int j = sab; i < n && j < sb; i++, j++)
			sum += p[i] * y;
		return sum >= k;
	}
	ll solve() {
		ll ans = 0;
		for (int i = 1 << 18; i; i >>= 1)
			if (!check(ans + i))
				ans += i;
		if (ans > n)
			return -1;
		while(check(ans)) ans--;
		return ans + 1;
	}
};
void solve() {
	solver x;
	x.read();
	cout << x.solve() << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
}