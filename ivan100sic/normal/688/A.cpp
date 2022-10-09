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

	int n, d, y=0, z=0;
	cin >> d >> n;
	while (n--) {
		string s;
		cin >> s;
		if (s == string(d, '1')) {
			z = 0;
		} else {
			z++;
			y = max(y, z);
		}
	}
	cout << y << '\n';
}