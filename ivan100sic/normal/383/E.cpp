#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1 << 24], n, z;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		a[1 << (s[0] -'a') | 1 << (s[1] - 'a') | 1 << (s[2] - 'a')]++;
	}

	for (int dir=1; dir<(1<<24); dir<<=1)
		for (int mask=0; mask<(1<<24); mask++)
			if (mask & dir)
				a[mask] += a[mask - dir];

	for (int i=0; i<(1<<24); i++)
		z ^= (n-a[i]) * (n-a[i]);

	cout << z << '\n';
}