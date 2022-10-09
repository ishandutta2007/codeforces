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
		int n, k, w;
		cin >> n >> k;
		if (k % 3)
			w = !!(n%3);
		else
			w = n%(k+1)%3 || n%(k+1)==k;
		cout << (w ? "Alice\n" : "Bob\n");
	}
}