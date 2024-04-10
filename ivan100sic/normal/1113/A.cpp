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

	int n, v;
	cin >> n >> v;
	v = min(n-1, v);
	int z = v;
	for (int i=2; i<=n-v; i++) {
		z += i;
	}
	cout << z << '\n';
}