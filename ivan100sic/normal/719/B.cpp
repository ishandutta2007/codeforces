#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

int resi(string s, string a) {
	int d = 0, b = 0;
	for (int i=0; i<n; i++) {
		if (s[i] != a[i])
			d++;
		b += s[i] == 'r' ? 1 : -1;
		b += a[i] == 'b' ? 1 : -1;
	}
	b = abs(b)/2;
	return b + (d - b) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> n >> s;
	string a;
	for (int i=0; i<n; i++)
		a += i%2 ? 'r' : 'b';
	int x = resi(s, a);
	for (char& c : a)
		c = 'r' ^ 'b' ^ c;
	cout << min(x, resi(s, a)) << '\n';
}