#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int l[5], r[5];
ld p[10005];

ld eq(int i, int x) {
	if (l[i] <= x && x <= r[i])
		return ld(1) / (r[i]-l[i]+1);
	else
		return 0;
}

ld le(int i, int x) {
	return min<ld>(1, max<ld>(0, x-l[i]+1) / (r[i]-l[i]+1));
}

ld ge(int i, int x) {
	return min<ld>(1, max<ld>(0, r[i]-x+1) / (r[i]-l[i]+1));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> l[i] >> r[i];

	ld e = 0;

	for (int x=1; x<=10000; x++) {
		ld q[5], r = 1;
		for (int i=0; i<n; i++) {
			// verovatnoca da su svi brojevi osim i-tog <= x
			ld p = 1;
			for (int k=0; k<n; k++) {
				if (k == i)
					continue;
				p *= le(k, x);
			}
			q[i] = p;
		}

		// svi su <= p
		for (int k=0; k<n; k++) {
			r *= le(k, x);
		}

		p[x] = accumulate(q, q+n, ld(0)) - (n-1)*r;
	}

	for (int x=1; x<=10000; x++)
		e += (p[x] - p[x-1]) * x;

	cout << setprecision(20) << fixed << e << '\n';
}