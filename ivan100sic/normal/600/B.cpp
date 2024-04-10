// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	sort(begin(a), end(a));
	while (m--) {
		int x;
		cin >> x;
		cout << upper_bound(begin(a), end(a), x) - begin(a) << ' ';
	}
	cout << '\n';
}