// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, p = 1, a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	if (n > m) {
		cout << "0\n";
		return 0;
	}
	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++)
			p = p * 1ll * abs(a[i] - a[j]) % m;
	cout << p << '\n';
}

// I will still practice daily...