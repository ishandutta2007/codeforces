#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int j = max_element(a, a+n) - a;
	sort(a, a+n);
	cout << j+1 << ' ' << a[n-2] << '\n';
}