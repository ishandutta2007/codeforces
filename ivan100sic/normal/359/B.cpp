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

	int n, k;
	cin >> n >> k;

	for (int i=0; i<n; i++) {
		if (i >= k)
			cout << 2*i+2 << ' ' << 2*i+1 << ' ';
		else
			cout << 2*i+1 << ' ' << 2*i+2 << ' ';
	}
	cout << '\n';
}