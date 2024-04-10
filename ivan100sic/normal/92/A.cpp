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

	int n, m, i=1;
	cin >> n >> m;
	while (m >= i) {
		m -= i;
		i++;
		if (i == n+1)
			i = 1;
	}
	cout << m << '\n';
}