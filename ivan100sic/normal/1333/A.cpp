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
		int n, m;
		cin >> n >> m;
		cout << 'W' << string(m-1, 'B') << '\n';
		for (int i=0; i<n-1; i++)
			cout << string(m, 'B') << '\n';
	}
}