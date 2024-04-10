#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

static int n;
static int x[100005];
static int a, b;
static int d[1000005];
static basic_string<int> marks[1000005];
static int offers[100005];

namespace offers_ms {
	int c[1000005];
	int sum = 0;
	int lb = -1;

	int steps_erase;

	static inline void erase(int x) {
		c[x]--;
		sum--;
		if (sum == 0) {
			lb = -1;
			return;
		}

		if (lb == x && c[x] == 0) {
			while (c[lb] == 0) {
				steps_erase++;
				lb++;
			}
		}
	}

	static inline int minkey() {
		return lb == -1 ? 123123123 : lb;
	}

	static inline void insert(int x) {
		c[x]++;
		sum++;
		lb = min(minkey(), x);
	}
};

static inline void generate() {
	n = 100000;
	for (int i=0; i<n; i++)
		x[i] = i+3;
	a = 998000000;
	b = 999000000;
}

static inline void readinput() {
	{
		int kk;
		n = 0;
		cin >> kk;
		while (kk--) {
			int y;
			cin >> y;
			if (y > 2)
				x[n++] = y;
		}
	}
	cin >> b >> a;
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// generate();
	readinput();

	sort(x, x+n);
	n = unique(x, x+n) - x;

	for (int i=0; i<n; i++) {
		int m = x[i];
		int l = (a+m-1)/m*m;
		if (l <= b)
			marks[l-a] += i;
	}

	for (int j : marks[0]) {
		offers[j] = 0;
		offers_ms::insert(0);
		if (a + x[j] <= b)
			marks[x[j]] += j;
	}

	for (int i=a+1; i<=b; i++) {
		// longjmps
		for (int j : marks[i-a]) {
			// skloni moj stari offer
			if (i-x[j] >= a) {
				offers_ms::erase(offers[j]);
			}
		}

		// sad racunaj
		d[i-a] = min(d[i-a-1] + 1, 1 + offers_ms::minkey());
		// sad dodaj ove nove offere
		for (int j : marks[i-a]) {
			int t = offers[j] = d[i-a];
			offers_ms::insert(t);
			if (i + x[j] <= b)
				marks[i-a+x[j]] += j;
		}

		marks[i-a].clear();
		marks[i-a].shrink_to_fit();
	}

	cerr << offers_ms::steps_erase << '\n';
	cout << d[b-a] << '\n';
}