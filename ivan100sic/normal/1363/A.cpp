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
		int n, x, k=0;
		cin >> n >> x;
		int e[2] = {0, 0};
		while (n--) {
			int q;
			cin >> q;
			e[q % 2]++;
		}

		for (int i=0; i<=x; i++) {
			int j = x-i;
			if (i <= e[0] && j <= e[1] && j % 2)
				k = 1;
		}

		cout << (k ? "Yes\n" : "No\n");
	}
}