#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, T;
int p[5005], t[5005];

vector<ld> sibaj(vector<ld> a, ld p, int k) {
	if (p == 0) {
		vector<ld> b(T+1);
		for (int i=k; i<=T; i++)
			b[i] = a[i-k];
		return b;
	}

	if (p > 0.99999) {
		vector<ld> b(T+1);
		for (int i=1; i<=T; i++)
			b[i] = a[i-1];
		return b;
	}

	vector<ld> b = a;

	b.pop_back();
	b.insert(b.begin(), 0);

	for (ld& x : b)
		x *= p;

	for (int i=1; i<=T; i++)
		b[i] += b[i-1] * (1 - p);

	ld dk = pow(1 - p, k);

	for (int i=T; i>=k; i--)
		b[i] -= b[i-k] * dk;

	for (int i=k; i<=T; i++)
		b[i] += a[i-k] * dk;

	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> T;
	for (int i=0; i<n; i++)
		cin >> p[i] >> t[i];

	ld sol = 0;

	vector<ld> a(T+1);
	a[0] = 1;

	for (int i=0; i<n; i++) {
		auto b = sibaj(a, p[i] * 0.01, t[i]);
		sol = accumulate(b.begin(), b.end(), sol);
		a = b;
	}

	cout << setprecision(20) << fixed << sol << '\n';
}