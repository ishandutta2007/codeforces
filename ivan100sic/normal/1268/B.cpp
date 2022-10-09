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
	ll z = 0, w = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		z += x/2 + (i % 2 && x % 2);
		w += x/2 + ((i+1) % 2 && x % 2);
	}
	cout << min(w, z) << '\n';
}