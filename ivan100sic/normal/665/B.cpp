// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;

	vector<int> q(k);
	for (int& x : q)
		cin >> x;

	int z = 0;
	while (n--) {
		for (int i=0; i<m; i++) {
			int x;
			cin >> x;
			auto it = find(begin(q), end(q), x);
			z += it - begin(q) + 1;
			rotate(begin(q), it, it+1);
		}
	}
	cout << z << '\n';
}