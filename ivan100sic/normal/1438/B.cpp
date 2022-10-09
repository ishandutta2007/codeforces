// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n, k=0;
		map<int, int> mp;
		cin >> n;
		for (int i=0; i<n; i++) {
			int x;
			cin >> x;
			if (mp[x]++) {
				k = 1;
			}
		}
		cout << (k ? "YES\n" : "NO\n");
	}
}