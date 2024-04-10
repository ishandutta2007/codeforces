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
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i=0; i<n; i++)
			cin >> a[i];
		if (n == 1) {
			if (a[0] % 2 == 0)
				cout << "1\n1\n";
			else
				cout << "-1\n";
		} else {
			if (a[0] % 2 == 0)
				cout << "1\n1\n";
			else if (a[1] % 2 == 0)
				cout << "1\n2\n";
			else
				cout << "2\n1 2\n";
		}
	}
}

// I will still practice daily...