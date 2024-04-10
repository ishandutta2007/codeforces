#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> ci;

int n;
ci a[1005], b[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		a[i] = {x, y};
	}
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		b[i] = {x, y};
	}
	sort(a, a+n);
	sort(b, b+n);
	reverse(b, b+n);
	cout << a[0].first + b[0].first << ' ' << a[0].second + b[0].second << '\n';
}