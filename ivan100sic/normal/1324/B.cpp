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

		int k = 0;
		for (int i=0; i<n; i++) {
			vector<int> f(n+1);
			for (int j=0; j<i; j++)
				f[a[j]]++;
			for (int j=i+1; j<n; j++)
				if (f[a[j]])
					k = 1;
		}

		cout << (k ? "YES\n" : "NO\n");
	}
}

// I will still practice daily...