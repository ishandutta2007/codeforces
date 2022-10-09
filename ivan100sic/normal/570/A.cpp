#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int winner(basic_string<int> a) {
	return max_element(a.begin(), a.end()) - a.begin();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> m >> n;
	basic_string<int> a(m, 0);
	for (int i=0; i<n; i++) {
		basic_string<int> b;
		for (int j=0; j<m; j++) {
			int x;
			cin >> x;
			b += x;
		}
		int y = winner(b);
		a[y]++;
	}
	cout << winner(a) + 1 << '\n';
}