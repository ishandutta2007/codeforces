#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int m = 998244353;

int n, k;
int a[200005];

int d12[200005], d11[200005], d1[200005], d[200005];

void calcd() {
	int p1 = 1, po = 0, p2 = 0;
	for (int i=0; i<200005; i++) {
		int t1 = (po * (k-2ll) + p2) % m;
		int t2 = (po * (k-2ll) + p1) % m;
		int to = (p1 + p2 + po * max(0ll, k-3ll)) % m;
		p1 = t1;
		p2 = t2;
		po = to;
		d11[i] = p1;
		d12[i] = p2;
	}

	d1[0] = 1;
	for (int i=1; i<200005; i++) {
		d1[i] = d1[i-1] * (k-1ll) % m;
	}
	d[0] = 1;
	d[1] = k;
	for (int i=2; i<200005; i++)
		d[i] = d[i-1] * (k-1ll) % m;
}

int ss(basic_string<int> b) {
	int n = b.size();
	int pref = 0, suff = 0;
	int stanje = 0, zadnji = 0, streak = 0, z = 1;
	for (int x : b) {
		if (stanje == 0) {
			if (x == -1) {
				pref++;
			} else {
				stanje = 1;
				zadnji = x;
				streak = 0;
			}
		} else if (stanje == 1) {
			if (x == -1) {
				streak++;
			} else {
				// zadnji, -1 * streak, x
				if (x != zadnji)
					z = z * 1ll * d12[streak] % m;
				else
					z = z * 1ll * d11[streak] % m;
				streak = 0;
				zadnji = x;
			}
		}
	}
	if (stanje == 0) {
		z = d[n];
	} else {
		suff = streak;
		z = z * 1ll * d1[pref] % m;
		z = z * 1ll * d1[suff] % m;
	}

	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	calcd();

	for (int i=1; i<=n; i++)
		cin >> a[i];
	basic_string<int> b;
	for (int i=1; i<=n; i+=2)
		b += a[i];
	int p = ss(b);
	b = {};
	for (int i=2; i<=n; i+=2)
		b += a[i];
	p = ss(b) * 1ll * p % m;
	cout << p << '\n';
}