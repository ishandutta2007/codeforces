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
	for (int i=0; i<n; i++)
		cin >> a[i];

	sort(a, a+n);
	int x = a[0] == 1 ? 1 : a[0] - 1, z = 1;
	for (int i=1; i<n; i++) {
		if (a[i] == x) {
			x++;
			z++;
		} else if (a[i] == x+1) {
			x = a[i];
			z++;
		} else if (a[i] > x+1) {
			x = a[i] - 1;
			z++;
		}
	}
	cout << z << '\n';
}