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

	int a, b, c;
	cin >> a >> b >> c;
	if (1.0 / a + 1.0 / b + 1.0 / c < 0.999) {
		cout << "NO\n";
		return 0;
	}
	for (int i=0; i<a; i++)
		for (int j=0; j<b; j++)
			for (int k=0; k<c; k++) {
				int q = 0;
				for (int x=0; x<100; x++) {
					if (x%a == i || x%b == j || x%c == k)
						q++;
				}
				if (q == 100) {
					cout << "YES\n";
					return 0;
				}
			}
	cout << "NO\n";

}