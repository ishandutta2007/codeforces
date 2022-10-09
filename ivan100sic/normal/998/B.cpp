#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, b;
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> b;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	int c[2] = {0, 0};
	multiset<int> s;
	for (int i=1; i<n; i++) {
		c[a[i] % 2]++;
		if (c[0] == c[1]) {
			s.insert(abs(a[i] - a[i+1]));
		}
	}
	int cc = 0;
	for (int x : s)
		if (b >= x) {
			b -= x;
			cc++;
		}
	cout << cc << '\n';
}