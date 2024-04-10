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
	cout << k*(6*n-1) << '\n';
	for (int i=0; i<n; i++) {
		cout << k*(6*i+1) << ' ' << k*(6*i+2) << ' '
			 << k*(6*i+3) << ' ' << k*(6*i+5) << '\n';
	}
}