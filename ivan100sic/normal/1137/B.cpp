#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a, b, n;
string s, t;
int f[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	for (char x : s)
		(x == '1' ? a : b)++;
	cin >> s;
	n = s.size();
	f[0] = -1;
	f[1] = 0;
	for (int i=2; i<=n; i++) {
		int x = f[i-1];
		while (x >= 0 && s[i-1] != s[x])
			x = f[x];
		f[i] = x+1;
	}

	int ka=0, kb=0;
	for (int i=f[n]; i<n; i++)
		(s[i] == '1' ? ka : kb)++;
	int sa=0, sb=0;
	for (char x : s)
		(x == '1' ? sa : sb)++;

	// moze prvo?
	if (sa <= a && sb <= b) {
		t += s;
		a -= sa;
		b -= sb;
		while (ka <= a && kb <= b) {
			t += s.substr(f[n]);
			a -= ka;
			b -= kb;
		}
	}
	while (a--) t += '1';
	while (b--) t += '0';
	cout << t << '\n';
}