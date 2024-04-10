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

	int n, b, d, z=0;
	cin >> n >> b >> d;
	int w = 0;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (x > b)
			continue;
		w += x;
		if (w > d) {
			w = 0;
			z++;
		}
	}
	cout << z << '\n';
}