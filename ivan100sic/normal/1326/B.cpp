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

	int n;
	cin >> n;
	ll s = 0;
	for (int i=1; i<=n; i++) {
		ll b;
		cin >> b;
		if (b >= 0)
			cout << (s += b) << ' ';
		else
			cout << (s + b) << ' ';
	}
	cout << '\n';

}

// I will still practice daily...