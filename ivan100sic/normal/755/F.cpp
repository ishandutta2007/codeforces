#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

int n, k;
int p[1000005];
bool v[1000005];

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int minimize(vector<int> a, int n, int k) {
	// ako postoji podskup zbira k, onda k, inace k+1
	int k0 = k;

	int g = 0;
	for (int x : a) {
		g = gcd(g, x);
	}

	if (k % g) {
		return k0 + 1;
	}

	k /= g;
	n /= g;
	for (int& x : a) {
		x /= g;
	}

	if (k > n-k) {
		k = n-k;
	}

	vector<bool> ok(k+1, false);

	map<int, int> c;
	for (int x : a) {
		c[x]++;
	}

	ok[0] = true;

	cerr << "here\n";

	for (auto p : c) {
		vector<int> dist(k+1, 11111111);
		for (int i=0; i<=min(k, p.first-1); i++) {
			if (ok[i]) {
				dist[i] = 0;
			}
		}
		for (int i=p.first; i<=k; i++) {
			if (ok[i]) {
				dist[i] = 0;
			} else {
				dist[i] = dist[i-p.first] + 1;
			}
		}
		for (int i=p.first; i<=k; i++) {
			if (dist[i] <= p.second) {
				ok[i] = true;
			}
		}
		if (ok[k]) {
			return k0;
		}
	}

	return ok[k] ? k0 : k0+1;
}

int maximize(vector<int> a, int k) {
	int sol = 0;
	for (int& x : a) {
		if (k >= x/2) {
			int dif = 2*(x/2);
			x -= dif;
			sol += dif;
			k -= dif/2;
		} else {
			int dif = 2*k;
			x -= dif;
			sol += dif;
			k = 0;
			return sol;
		}
	}

	// drugi prolaz, sto ostane
	for (int& x : a) {
		if (x == 1 && k > 0) {
			x = 0;
			k--;
			sol++;
		}
	}

	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> p[i];
	}

	vector<int> cyc;

	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			v[i] = true;
			int x = i, c = 0;
			do {
				x = p[x];
				v[x] = true;
				c++;
			} while (x != i);
			cyc.push_back(c);
		}
	}

	/*
	for (int c : cyc) {
		cerr << c << ' ';
	}
	cerr << '\n';
	*/
	// sort(cyc.begin(), cyc.end());
	// reverse(cyc.begin(), cyc.end());

	cout << minimize(cyc, n, k) << ' ' << maximize(cyc, k) << '\n';
}