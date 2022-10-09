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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;
		set<int> s(begin(a), end(a));
		int q = s.size();
		if (q > k) {
			cout << "-1\n";
			continue;
		}

		cout << k * n << '\n';
		while (n--) {
			for (int x : s)
				cout << x << ' ';
			for (int i=0; i<k-q; i++)
				cout << "1 ";
		}
		cout << '\n';
	}
}