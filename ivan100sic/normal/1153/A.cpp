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

	int n, t;
	cin >> n >> t;
	int o = -1, q = 123123123;
	for (int i=1; i<=n; i++) {
		int s, d;
		cin >> s >> d;
		while (s < t)
			s += d;
		if (s < q)
			q = s, o = i;
	}
	cout << o << '\n';
}