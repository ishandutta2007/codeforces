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

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	ll z = 0;
	for (int i=0; i<n; i++)
		z += min(i+2, n) * 1ll * a[i];
	cout << z << '\n';
}