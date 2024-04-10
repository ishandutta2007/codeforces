#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
using namespace std;

struct seg {
	long long x, t, id;

	// t = 0 : zatvara
	// t = 1 : otvara

	bool operator< (const seg& other) const {
		return x < other.x || (x == other.x && t < other.t);
	}
};

int n, k;
seg a[300005], b[300005], c[600005];
long long l[300005], r[300005];

void spremi() {
	for (int i=0; i<n; i++) {
		a[i].x = l[i];
		a[i].t = 1;
		a[i].id = i;

		b[i].x = r[i] + 1;
		b[i].t = 0;
		b[i].id = i;
	}
	sort(a, a+n);
	sort(b, b+n);
}

pair<long long, long long> nadjibr(long long shift) {
	for (int i=0; i<n; i++) {
		b[i].x -= shift;
	}
	merge(a, a+n, b, b+n, c);
	for (int i=0; i<n; i++) {
		b[i].x += shift;
	}

	long long open=0, best=0, bx=0;

	for (int i=0; i<2*n; i++) {
		if (r[c[i].id] - l[c[i].id] + 1 < shift) {
			continue;
		}


		if (c[i].t == 0) {
			open--;
		} else {
			open++;
		}

		if (open > best) {
			best = open;
			bx = c[i].x;
		}
	}

	return {best, bx};
}

void print(long long x, long long shift) {
	int k = 0;
	for (int i=0; i<n; i++) {
		if (l[i] <= x && x <= r[i] - shift) {
			cout << i+1 << ' ';
			k++;
			if (k == ::k) {
				break;
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> l[i] >> r[i];
	}
	spremi();

	long long l = 0, r = 4e9, o = -1;
	long long ox;

	while (l <= r) {
		long long m = (l+r) / 2;

		auto p = nadjibr(m);

		cerr << m << ' ' << p.first << ' ' << p.second << "\n\n";

		if (p.first >= k) {
			o = m;
			ox = p.second;
			l = m+1;
		} else {
			r = m-1;
		}
	}

	cout << o+1 << '\n';

	if (o == -1) {
		for (int i=1; i<=k; i++) {
			cout << i << ' ';
		}
	} else {
		print(ox, o);
	}
	

}