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
		for (int j=0; j<n; j++) 
			cout << (i == j ? k : 0) << ' ';
		cout << '\n';
	}
}