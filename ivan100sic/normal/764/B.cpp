#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n-i+1; i++) {
		if (i % 2)
			swap(a[i], a[n-i+1]);
	}
	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}