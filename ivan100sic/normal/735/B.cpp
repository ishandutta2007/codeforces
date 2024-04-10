#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, u, v;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> u >> v;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n, greater<int>());
	ld x1 = accumulate(a, a+u, 0ll);
	ld y1 = accumulate(a+u, a+u+v, 0ll);
	swap(u, v);
	ld x2 = accumulate(a, a+u, 0ll);
	ld y2 = accumulate(a+u, a+u+v, 0ll);
	swap(u, v);
	cout << setprecision(20) << fixed << max(x1/u + y1/v, x2/v + y2/u) << '\n';
}