#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, z = 12312123;
string s, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s >> t;
	basic_string<int> e;
	for (int i=0; i<=m-n; i++) {
		int d = 0;
		for (int j=0; j<n; j++) 
			if (s[j] != t[i+j])
				d++;

		if (d < z) {
			z = d;
			e = {};
			for (int j=0; j<n; j++) 
				if (s[j] != t[i+j])
					e += j+1;
		}
	}

	cout << z << '\n';
	for (int x : e)
		cout << x << ' ';
	cout << '\n';
}