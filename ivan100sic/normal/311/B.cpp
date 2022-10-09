// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, p;
int z[100005];
int a[100005];
ll q[100005];

ll cost(int l, int r) {
	return a[r] * (r-l) - (q[r] - q[l]);
}

struct line {
	ll k, b;
	ld operator* (ld x) {
		return k*x + b;
	}
	ld l;
};

struct liner {
	vector<line> a;
	int pos;

	liner() { 
		pos = 0;
	}

	// mora opadajuci koeficijenti
	void add(ll k, ll b) {
		line tmp {k, b, 0};
		while (a.size() && tmp*a.back().l <= a.back()*a.back().l)
			a.pop_back();
		ld l = -1e10;
		if (a.size()) {
			auto [kk, bb, _] = a.back();
			l = ld(b - bb) / (kk - k);
		}
		// cerr << "dod " << k << ' ' << b << ' ' << l << '\n';
		a.push_back({k, b, l});
	}

	// mora rastuce
	ll scan(ll x) {
		pos = min(pos, (int)a.size() - 1);
		while (pos+1 < (int)a.size())
			if (x >= a[pos+1].l)
				pos++;
			else
				break;
		// cerr << "scan " << a[pos]*x << " pos = " << pos << "/" << a.size() << '\n';
		return a[pos]*x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> p;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		z[i] = z[i-1] + x;
	}

	for (int i=0; i<m; i++) {
		int h, t;
		cin >> h >> t;
		a[i+1] = t - z[h];
	}
	sort(a+1, a+m+1);
	for (int i=1; i<=m; i++)
		q[i] = q[i-1] + a[i];

	// for (int i=1; i<=m; i++)
	// 	cerr << a[i] << " \n"[i == m];

	vector<ll> ol(m+1, 1e18);
	ol[0] = 0;
	while (p--) {
		auto nu = ol;

		/*
		int j = 0;
		for (int i=1; i<=m; i++) {
			while (j < i && ol[j+1] + cost(j+1, i) <= ol[j] + cost(j, i))
				j++;
			nu[i] = min(nu[i], ol[j] + cost(j, i));
		}
		*/

		/*
		for (int i=1; i<=m; i++) {
			for (int j=0; j<i; j++)
				nu[i] = min(nu[i], ol[j] + cost(j, i));
		}
		*/

		liner tr;
		for (int i=1; i<=m; i++) {
			int j = i-1;
			tr.add(-j, ol[j]+q[j]);
			nu[i] = min(nu[i], i*1ll*a[i] - q[i] + tr.scan(a[i]));
		}

		// for (int i=0; i<=m; i++)
		// 	cerr << nu[i] << " \n"[i == m];
		swap(ol, nu);
	}
	cout << ol[m] << '\n';
}

// I will still practice daily...