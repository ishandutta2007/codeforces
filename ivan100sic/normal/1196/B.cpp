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

	int q;
	cin >> q;
	while (q--) {
		int n, k;
		cin >> n >> k;
		basic_string<int> odd;
		for (int i=1; i<=n; i++) {
			int x;
			cin >> x;
			if (x % 2)
				odd += i;
		}
		if ((int)odd.size() < k || (int)odd.size() % 2 != k % 2) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
			for (int i=0; i<k-1; i++)
				cout << odd[i] << ' ';
			cout << n << '\n';
		}
	}
}