#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int x[100005], y[100005];
int xr[100005], yr[100005];
int t[100005][4];
basic_string<pair<int, int>> uq;
basic_string<int> rey[305];

ll sol[100005];

int nadji(int x, int y) {
	return lower_bound(uq.begin(), uq.end(), pair<int, int>{x, y}) - uq.begin();
}

namespace tracker {
	int a[400005], b[100005], bch[100005], vreme = -1;

	void set_b(int x, int y) {
		sol[x] += (vreme - bch[x]) * b[x]; 
		b[x] = y;
		bch[x] = vreme;
	}

	void dodaj(int x) {
		set_b(a[x], b[a[x]] - 1);
		a[x]++;
		set_b(a[x], b[a[x]] + 1);
	}

	void skini(int x) {
		set_b(a[x], b[a[x]] - 1);
		a[x]--;
		set_b(a[x], b[a[x]] + 1);
	}

	void tick() {
		vreme++;
	}

	void flush() {
		for (int x=1; x<=n; x++) {
			sol[x] += (vreme - bch[x]) * b[x];
		}
		fill(a, a+400005, 0);
		fill(b, b+100005, 0);
		vreme = -1;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		a += 1e9;
		b += 1e9;
		x[i] = a;
		y[i] = b;
		xr[i] = a % k;
		yr[i] = b % k;
		rey[yr[i]] += i;
		uq += {a/k, b/k};
		uq += {a/k-1, b/k};
		uq += {a/k, b/k-1};
		uq += {a/k-1, b/k-1};
	}
	sort(uq.begin(), uq.end());
	uq.resize(unique(uq.begin(), uq.end()) - uq.begin());
	for (int i=0; i<n; i++) {
		int a = x[i], b = y[i];
		t[i][0] = nadji(a/k, b/k);
		t[i][1] = nadji(a/k-1, b/k);
		t[i][2] = nadji(a/k, b/k-1);
		t[i][3] = nadji(a/k-1, b/k-1);
	}

	for (int q=0; q<k; q++) {
		// dodaj
		for (int i=0; i<n; i++)
			if (q <= xr[i])
				tracker::dodaj(t[i][0]);
			else
				tracker::dodaj(t[i][1]);

		tracker::tick();
		for (int j=1; j<k; j++) {
			// prebaci ove sa ostatkom j
			for (int i : rey[j-1]) {
				if (q <= xr[i]) {
					tracker::skini(t[i][0]);
					tracker::dodaj(t[i][2]);
				} else {
					tracker::skini(t[i][1]);
					tracker::dodaj(t[i][3]);
				}
			}
			tracker::tick();
		}
		tracker::flush();
	}

	for (int i=1; i<=n; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}