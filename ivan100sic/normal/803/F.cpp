#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int mod = 1'000'000'007;

int n;
int c[100005], d[100005];
int pw2[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}
	pw2[0] = 1;
	for (int i=1; i<=100000; i++) {
		pw2[i] = pw2[i-1] + pw2[i-1];
		if (pw2[i] >= mod)
			pw2[i] -= mod;
		for (int j=i; j<=100000; j+=i) {
			d[i] += c[j];
		}
	}
	for (int i=1; i<=100000; i++)
		d[i] = pw2[d[i]] - 1;
	for (int j=100000; j>=1; j--) {
		for (int i=2*j; i<=100000; i+=j) {
			d[j] = (d[j] + mod - d[i]);
			if (d[j] >= mod)
				d[j] -= mod;
		}
	}
	cout << d[1] << '\n';
}