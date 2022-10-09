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
	string s, p;
	cin >> n >> s;

	int pot = (n-11)/2;

	int u = 0;
	for (int i=0; i<n; i++) {
		if (u < pot && s[i] == '8') {
			// brisi
			u++;
		} else {
			p += s[i];
		}
	}

	int f = find(p.begin(), p.end(), '8') - p.begin();
	cout << (f <= pot ? "YES\n" : "NO\n");
}