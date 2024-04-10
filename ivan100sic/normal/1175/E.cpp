#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r;
	bool operator< (const seg& b) const {
		if (l != b.l)
			return l < b.l;
		return r > b.r;
	}
} a[200005];

int n, q;
int nx[200005][18];

void sredi() {
	sort(a, a+n);
	int k = 1;
	for (int i=1; i<n; i++) {
		if (a[i].r > a[k-1].r) {
			a[k++] = a[i];
		}
	}
	n = k;
}

int nadji_prvog(int x) {
	int l = 0, r = n-1, o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (a[m].l <= x) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return o;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=0; i<n; i++)
		cin >> a[i].l >> a[i].r;
	sredi();
	int j = 0;
	for (int i=0; i<n; i++) {
		j = max(j, i);
		while (j+1 < n && a[j+1].l <= a[i].r)
			j++;
		nx[i][0] = j;
	}
	for (int l=1; l<18; l++) {
		for (int i=0; i<n; i++) {
			nx[i][l] = nx[nx[i][l-1]][l-1];
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		int p = nadji_prvog(l);
		if (p == -1 || a[p].r < l) {
			cout << "-1\n";
		} else {
			int z = 1;
			for (int q=17; q>=0; q--) {
				if (a[nx[p][q]].r >= r) {
					// previse?
				} else {
					z += 1 << q;
					p = nx[p][q];
				}
			}
			if (a[p].r < r) {
				p = nx[p][0];
				z++;
			}
			
			if (a[p].r < r) {
				cout << "-1\n";
			} else {
				cout << z << '\n';
			}
		}
	}
}