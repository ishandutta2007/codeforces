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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x : a)
			cin >> x;
		sort(a.begin(), a.end());
		int z = 1;
		for (int i=1; i<n; i++)
			if (a[i] == a[i-1] + 1)
				z = 2;
		cout << z << '\n';
	}
}