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

	int n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << "1\n";
	} else if (m-1 >= n-m) {
		cout << m-1 << '\n';
	} else {
		cout << m+1 << '\n';
	}
}