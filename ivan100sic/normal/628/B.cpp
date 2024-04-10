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

	string s;
	cin >> s;
	int n = s.size();
	ll sol = 0;
	for (int i=0; i<n; i++) {
		if (i == 0) {
			if (s[i] % 4 == 0)
				sol++;
		} else {
			if (s[i] % 4 == 0)
				sol++;
			int x = (int)(s[i-1] - 48) * 10 + (s[i] - 48);
			if (x % 4 == 0)
				sol += i;
		}
	}
	cout << sol << '\n';
}