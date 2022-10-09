#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			int x;
			cin >> x;
			if (i != j) {
				if (x & 1)
					c[i] = 1;
				if (x & 2)
					c[j] = 1;
			}
		}
	}

	basic_string<int> z;
	for (int i=1; i<=n; i++)
		if (!c[i])
			z += i;
	cout << size(z) << '\n';
	for (int x : z)
		cout << x << ' ';
	cout << '\n';
}