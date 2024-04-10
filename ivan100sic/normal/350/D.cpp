#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

struct line {
	int a, b, c;

	template<class pt>
	line(pt u, pt v) {
		a = u.y - v.y;
		b = v.x - u.x;
		c = a*v.x + b*v.y;
		normalizuj();
		// cerr << "given: " << u.x << ' ' << u.y << ' ' << v.x << ' ' << v.y << '\n';
		// cerr << "line constructed: " << a << ' ' << b << ' ' << c << '\n';
	}

	ll hash() const {
		return a + 44'444 * b + 444'444'444ll * c;
	}

	void normalizuj() {
		int g = gcd(gcd(abs(a), abs(b)), abs(c));
		a /= g;
		b /= g;
		c /= g;
		if (a < 0 || (a == 0 && b < 0)) {
			a *= -1;
			b *= -1;
			c *= -1;
		}
	}
};

struct pt {
	int x, y;
	bool operator< (pt b) const {
		if (x != b.x)
			return x < b.x;
		return y < b.y;
	}
};

struct event {
	pt p;
	int z;
	bool operator< (event b) const {
		return p < b.p;
	}
};

map<ll, basic_string<event>> mp;

int n, m;
pt u[300005], v[300005];
pt c[1505];
int rad[1505];

ll kv(ll x) {
	return x*x;
}

ll d2(pt a, pt b) {
	return kv(a.x-b.x) + kv(a.y-b.y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> u[i].x >> u[i].y >> v[i].x >> v[i].y;
		u[i].x *= 2;
		v[i].x *= 2;
		u[i].y *= 2;
		v[i].y *= 2;
		if (v[i] < u[i])
			swap(u[i], v[i]);
		line l(u[i], v[i]);
		ll lh = l.hash();
		mp[lh] += {u[i], +1};
		mp[lh] += {{v[i].x, v[i].y+1}, -1};
	}
	for (auto& b : mp) {
		sort(b.second.begin(), b.second.end());
		int z = 0;
		for (auto& e : b.second) {
			int t = e.z;
			e.z = z;
			// cerr << "! " << e.p.x << ' ' << e.p.y << ' ' << e.z << '\n';
			z += t;
		}
	}
	for (int i=0; i<m; i++) {
		cin >> c[i].x >> c[i].y >> rad[i];
		c[i].x *= 2;
		c[i].y *= 2;
		rad[i] *= 2;
	}

	ll sol = 0;
	for (int i=0; i<m; i++) {
		for (int j=i+1; j<m; j++) {
			if (rad[i] != rad[j])
				continue;
			if (d2(c[i], c[j]) <= 4*rad[i]*rad[i])
				continue;
			pt sred = {(c[i].x + c[j].x)/2, (c[i].y + c[j].y) / 2};
			pt away = {sred.x + (c[i].y - c[j].y), sred.y + (c[j].x - c[i].x)};
			line l(sred, away);
			ll lh = l.hash();
			auto mpit = mp.find(lh);
			if (mpit == mp.end())
				continue;
			// cerr << "ask " << sred.x << ' ' << sred.y << "\n";
			auto it = upper_bound(mpit->second.begin(), mpit->second.end(), 
				event{sred, 0});
			if (it == mpit->second.end())
				continue;
			sol += it->z;
		}
	}
	cout << sol << '\n';
}