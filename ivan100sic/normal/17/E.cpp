#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

static const int M = 51123987;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

vector<int> manacher(const string& s) {
	int n = s.size();
	vector<int> w(n);
	for (int i=1, l=0, r=0; i<n; i++) {
		if (i <= r) {
			w[i] = min(r-i, w[r+l-i]);
		}
		while (i-w[i]-1 >= 0 && i+w[i]+1 < n
			&& s[i-w[i]-1] == s[i+w[i]+1])
		{
			w[i]++;
		}
		if (i + w[i] > r) {
			r = i + w[i];
			l = i - w[i];
		}
	}
	return w;
}

vector<int> manacher_brut(const string& s) {
	int n = s.size();
	vector<int> w(n);
	for (int i=0; i<n; i++) {
		w[i] = 0;
		while (i-w[i]-1 >= 0 && i+w[i]+1 < n
			&& s[i-w[i]-1] == s[i+w[i]+1])
		{
			w[i]++;
		}
	}
	return w;
}

string expand(const string& s) {
	string p(2*s.size()+1, '#');
	for (int i=0; i<(int)s.size(); i++)
		p[2*i+1] = s[i];
	return p;
}

string generate(int n) {
	string s(n, 0);
	for (char& x : s)
		x = uniform_int_distribution<int>(0, 20)(eng) / 18;
	return s;
}

void stress_manacher() {
	while (1) {
		string s = generate(100);
		auto v1 = manacher(s);
		auto v2 = manacher_brut(s);
		if (v1 != v2) {
			cerr << "Fail!\n";
			cerr << s << '\n';
			return;
		} else {
			// cerr << "OK\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// stress_manacher();	
	int n;
	string s;
	cin >> n >> s;
	s = expand(s);
	n = 2*n+1;
	auto w = manacher(s);

	vector<ll> cr2(n+1);
	for (int i=0; i<n; i++) {
		if (s[i] == '#') {
			cr2[i+1] += 1;
			cr2[i+w[i]+1] -= 1;
		} else {
			cr2[i] += 1;
			cr2[i+w[i]+1] -= 1;
		}
	}
	ll sol = 0;

	for (int i=2; i<=n; i++) {
		cr2[i] += cr2[i-2];
		cr2[i] %= M;
	}

	// for (int i=0; i<=n; i++) {
	// 	cerr << cr2[i] << ' ';
	// }
	// cerr << " ~~\n";

	for (int i=2; i<=n; i++) {
		cr2[i] += cr2[i-2];
		cr2[i] %= M;
	}

	ll ima_pal = cr2[n] % M;
	ll parova = ima_pal * (ima_pal-1) / 2 % M;

	// for (int i=0; i<=n; i++) {
	// 	cerr << cr2[i] << ' ';
	// }
	// cerr << " ~~\n";

	for (int i=2; i<=n; i++) {
		cr2[i] += cr2[i-2];
		cr2[i] %= M;
	}

	// for (int i=0; i<=n; i++) {
	// 	cerr << cr2[i] << ' ';
	// }
	// cerr << " ~~\n";

	// for (int i=0; i<n; i++) {
	// 	cerr << s[i] << ' ';
	// }
	// cerr << " ~~\n";

	auto daj = [&](int x) {
		return x >= 0 ? cr2[x] : 0;
	};

	for (int i=0; i<n; i++) {
		if (s[i] == '#') {
			sol += daj(i-3) - daj(i-w[i]-3);
		} else {
			sol += daj(i-2) - daj(i-w[i]-3);
		}
		// cerr << "sol = " << sol << '\n';
	}

	sol = parova - sol;

	sol %= M;
	if (sol < 0)
		sol += M;
	cout << sol << '\n';
}