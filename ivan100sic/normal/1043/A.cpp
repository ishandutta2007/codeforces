#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];

bool ok(int k) {
	int x = 0;
	int y = 0;
	for (int i=1; i<=n; i++) {
		x += k - a[i];
		y += a[i];
	}
	return x > y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int k = *max_element(a+1, a+n+1);
	while (!ok(k)) k++;

	cout << k << '\n';
}