#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	int s = 0, cnt = 0, i = n - 1;
	while (s < m) {
		s += a[i];
		++cnt;
		--i;
	}
	cout << cnt << '\n';
}