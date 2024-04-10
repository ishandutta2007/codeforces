#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x, y;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x >> y;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int i=0; i<n; i++) {
		int l = max(0, i-x);
		int r = min(n, i+y+1);
		if (min_element(a+l, a+r) == a+i) {
			cout << i+1 << '\n';
			return 0;
		}
	}
}