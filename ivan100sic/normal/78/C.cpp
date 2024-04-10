#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct mexer {
	set<int> s;
	void add(int x) { s.insert(x); };
	int get() {
		for (int i=0;; i++) 
			if (!s.count(i))
				return i;
	}
};

map<int, int> cache;
vector<int> p;

int grundy(int x, int k) {
	if (cache.count(x))
		return cache[x];
	mexer mx;
	for (int q : p)
		if (q > 1 && x % q == 0 && x / q >= k)
			mx.add(grundy(x/q, k));
	return cache[x] = mx.get();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	if (n % 2 == 0) {
		cout << "Marsel\n";
		return 0;
	}

	for (int i=1; i*i <= m; i++) {
		if (m % i == 0) {
			p.push_back(i);
			p.push_back(m/i);
		}
	}
	sort(p.begin(), p.end());
	p.erase(unique(p.begin(), p.end()), p.end());

	int g = grundy(m, k);
	cout << (g ? "Timur\n" : "Marsel\n");
}