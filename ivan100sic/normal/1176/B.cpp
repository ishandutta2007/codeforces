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

	int t;
	cin >> t;
	while (t--) {
		int a[3] = {0, 0, 0};
		int n;
		cin >> n;
		while (n--) {
			int x;
			cin >> x;
			a[x%3]++;
		}
		int z = 0;
		for (int i=0; i<=min(a[2], a[1]); i++)
			z = max(z, a[0] + i + (a[1]-i)/3 + (a[2]-i) / 3);
		cout << z << '\n';
	}
}