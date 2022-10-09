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
	int c[2] = {0, 0};
	while (n--) {
		int x;
		cin >> x;
		c[x%2]++;
	}
	cout << min(c[0], c[1]) << '\n';
}