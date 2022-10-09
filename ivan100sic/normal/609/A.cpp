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

	int n, m, c=0;
	cin >> n >> m;
	vector<int> a(n);
	for (int& x : a)
		cin >> x;
	sort(a.begin(), a.end(), greater<int>());
	for (int x : a) {
		if (m > 0)
			c++;
		m -= x;
	}
	cout << c << '\n';
}