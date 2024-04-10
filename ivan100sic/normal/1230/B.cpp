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

	int n, k;
	string s;
	cin >> n >> k >> s;

	if (n == 1) {
		if (k == 1)
			cout << "0\n";
		else
			cout << s << '\n';
		return 0;
	}

	for (int i=0; i<n; i++) {
		char l = i ? '0' : '1';
		if (s[i] != l && k)
			k--, s[i] = l;
		cout << s[i];
	}
	cout << '\n';
}