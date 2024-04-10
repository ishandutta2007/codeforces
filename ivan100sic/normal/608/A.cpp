#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int relu(int x) {
	if (x < 0)
		return 0;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, s;
	cin >> n >> s;
	int z = 0;
	while (n--) {
		int f, t;
		cin >> f >> t;
		z = max(z, relu(t - (s-f)));
	}
	cout << z + s << '\n';
}