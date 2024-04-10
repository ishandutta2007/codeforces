#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[100005];
basic_string<int> sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	int zbir = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		zbir += a[i];
	}
	if (zbir % k) {
		cout << "No\n";
		return 0;
	}
	k = zbir / k;

	int z = 0, last = 0;
	for (int i=1; i<=n; i++) {
		int x = a[i];
		z += x;
		if (z == k) {
			sol += i - last;
			last = i;
			z = 0;
		} else if (z > k) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}