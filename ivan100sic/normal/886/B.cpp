#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int v[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		v[x] = i;
	}
	int b = -1;
	for (int i=0; i<=200000; i++) {
		if (v[i] > 0 && (b == -1 || v[i] < v[b]))
			b = i;
	}
	cout << b << '\n';
}