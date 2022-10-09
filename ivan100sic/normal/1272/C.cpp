#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool b[256];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	for (int i=0; i<k; i++) {
		char x;
		cin >> x;
		b[x] = 1;
	}

	ll sol = 0;
	int str = 0;
	for (int i=0; i<n; i++) {
		if (b[s[i]])
			str++;
		else
			str = 0;
		sol += str;
	}
	cout << sol << '\n';
}