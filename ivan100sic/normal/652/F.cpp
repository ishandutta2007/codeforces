// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

typedef __int128 lll;

struct ant {
	int p, d, i;

	template<class T>
	auto operator< (const T& b) const {
		return p < b.p;
	}
};

int n, m;
ll t;
ant a[300005];
ll pos[300005];
ll ans[300005];
lll zk;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> t;
	for (int i=0; i<n; i++) {
		char c;
		cin >> a[i].p >> c;
		a[i].p %= m;
		a[i].d = c == 'L' ? -1 : 1;
		a[i].i = i;
	}

	sort(a, a+n);
	for (int i=0; i<n; i++) {
		zk += a[i].p + t * a[i].d;
		pos[i] = ((a[i].p + t * a[i].d) % m + m) % m;
	}

	sort(pos, pos+n);
	lll raz = (zk - accumulate(pos, pos+n, lll(0))) / m;
	ll y = ((raz % n) + n) % n;
	for (int i=0; i<y; i++)
		pos[i] += m;
	sort(pos, pos+n);
	for (int i=0; i<n; i++)
		ans[a[i].i] = pos[i] % m;
	for (int i=0; i<n; i++)
		cout << (ans[i] ? ans[i] : m) << " \n"[i == n-1];
}