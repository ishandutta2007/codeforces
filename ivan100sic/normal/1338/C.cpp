#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void play() {
	set<int> s;
	int r = 80;
	while (r--) {
		for (int a=1; a<10000; a++) {
			if (s.count(a))
				continue;
			for (int b=1; b<10000; b++) {
				if (s.count(b))
					continue;
				int c = a ^ b;
				if (c == 0 || s.count(c))
					continue;
				s.insert(a);
				s.insert(b);
				s.insert(c);
				cout << a << ' ' << b << ' ' << c << '\n';
				a = 123123;
				break;
			}
		}
	}
}

struct info {
	ll x, y, z;
};

map<ll, info> kes;

info resi(ll i, ll t) {
	if (i == 0)
		return {1, 2, 3};
	if (i == 1) {
		if (t == 0)
			return {4, 8, 12};
		if (t == 1)
			return {5, 10, 15};
		if (t == 2)
			return {6, 11, 13};
		return {7, 9, 14};
	}

	auto it = kes.find(i + 40*t);
	if (it != kes.end())
		return it->second;
	info& u = kes[i + 40*t];

	ll q = 1ll << (2*i - 2);
	info b = resi(i-1, t / q * q / 4);
	b.x *= 4;
	b.y *= 4;
	b.z *= 4;
	info ta = resi(i-1, t % q);
	info tb = resi(i-1, 0);
	b.x += ta.x - tb.x;
	b.y += ta.y - tb.y;
	b.z += ta.z - tb.z;
	return u = b;
}

info resi(ll t) {
	for (ll g=0;; g++) {
		ll sz = 1ll << (2*g);
		if (t < sz)
			return resi(g, t);
		t -= sz;
	}
}

void test() {
	for (int i=0; i<80; i++) {
		info r = resi(i);
		cerr << r.x << ' ' << r.y << ' ' << r.z << '\n';
	}
}

void stress() {
	ll z = 0;
	int r = 100000;
	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	while (r--) {
		uniform_int_distribution<ll> uid(0, 1e16);
		z ^= resi(uid(eng)).x;
	}
	cerr << z << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// stress();
	// return 0;
	//
	// play();
	// test();

	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		x--;
		ll y = x / 3, z = x % 3;
		auto r = resi(y);
		ll a[3] = {r.x, r.y, r.z};
		cout << a[z] << '\n';
	}
}