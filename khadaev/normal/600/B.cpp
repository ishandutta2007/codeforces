#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> a(n), b(m);
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
	sort(a.begin(), a.end());
	for (int i = 0; i < m; ++i) printf("%d ", upper_bound(a.begin(),
		a.end(), b[i]) - a.begin());
}