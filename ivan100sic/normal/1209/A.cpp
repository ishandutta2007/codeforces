#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool u[105];
int n, a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	int c = 0, v = 0;
	while (v < n) {
		int j = -1;
		for (int i=0; i<n; i++) {
			if (!u[i]) {
				if (j == -1 || a[i] < a[j])
					j = i;
			}
		}
		for (int i=0; i<n; i++)
			if (!u[i] && a[i] % a[j] == 0)
				u[i] = 1, v++;
		c++;
	}
	cout << c << '\n';
}