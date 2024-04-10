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
	iota(a, a+n+1, 0);

	for (int i=n; i>1; i--)
		swap(a[i], a[i-1]);

	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}