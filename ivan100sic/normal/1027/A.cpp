#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool sus(int x, int y) {
	if (abs(x-y) == 0 || abs(x-y) == 2)
		return true;

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int k = 1;
		for (int i=0; i<n; i++) {
			int j = n-1-i;
			if (i == j)
				continue;
			if (!sus(s[i], s[j]))
				k = 0;
		}
		cout << (k ? "YES\n" : "NO\n");
	}
}