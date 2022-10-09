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

	bool duplo = false;
	bool ok = false;

	for (int i=0; i<n-1; i++) {
		if (s[i] != '?' && s[i] == s[i+1])
			duplo = true;
		else if (s[i] == '?' && s[i+1] == '?')
			ok = true;

		if (i > 0 && i < n-1) {
			if (s[i] == '?' && s[i-1] != '?' && s[i+1] != '?' && s[i-1] == s[i+1])
				ok = true;
		}
	}

	if (s[0] == '?')
		ok = true;
	if (s[n-1] == '?')
		ok = true;

	if (duplo)
		ok = false;

	cout << (ok ? "Yes\n" : "No\n");
}