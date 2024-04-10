#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	string s;
	cin >> n >> s;
	map<int, int> sol;
	for (int l=1; l<=n; l++) {
		if (n % l)
			continue;
		int p = 0;
		for (int i=0; i<l; i++) {
			int z = 0;
			for (int j=i; j<n; j+=l)
				z = z ^ (s[j] - '0');
			p += z;
		}
		sol[l] = !p;
	}
	int z = 0;
	for (int k=0; k<n; k++)
		z += sol[gcd(n, k)];
	cout << z << '\n';
}