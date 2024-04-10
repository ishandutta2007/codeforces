// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct brojac {
	vector<int> c;
	int d;

	brojac() : c(1000005), d(0) {}

	void add(int x) {
		if (c[x]++ == 0) {
			d++;
		}
	}

	void rem(int x) {
		if (c[x]-- == 1) {
			d--;
		}
	}

	int operator() () {
		return d;
	}
};

int n, k;
int a[1000005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	brojac br;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	int r = 0;
	int ul = 0, ur = 1;
	for (int l=0; l<n; l++) {
		while (r < n) {
			br.add(a[r++]);
			if (br() > k) {
				br.rem(a[--r]);
				break;
			}
		}

		if (r-l > ur-ul)
			ur = r, ul = l;

		br.rem(a[l]);
	}

	cout << ul+1 << ' ' << ur << '\n';
}