// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
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
		int n, y=0, l=1e9;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		l = *min_element(begin(a), end(a));
		for (int i=0; i<n; i++)
			y += (a[i] - l) % 2;
		if (y == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

}

// I will still practice daily...