#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q, z;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q >> s;
	for (int i=0; i<n-1; i++)
		if (s[i] == s[i+1] && s[i+1] == '.')
			z++;

	while (q--) {
		int x; char y;
		cin >> x >> y;
		x--;

		if (s[x] == '.' && x > 0 && s[x-1] == '.')
			z--;
		if (s[x] == '.' && x+1 < n && s[x+1] == '.')
			z--;

		s[x] = y;

		if (s[x] == '.' && x > 0 && s[x-1] == '.')
			z++;
		if (s[x] == '.' && x+1 < n && s[x+1] == '.')
			z++;

		cout << z << '\n';
	}
}