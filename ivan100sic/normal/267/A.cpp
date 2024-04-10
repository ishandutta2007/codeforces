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

	while (n--) {
		int a, b, z = 0;
		cin >> a >> b;
		while (a > 0 && b > 0) {
			if (a > b) {
				swap(a, b);
			}
			if (a == b) {
				z++;
				a = 0;
			} else {
				z += b/a;
				b %= a;
			}
		}
		cout << z << '\n';
	}
}