#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];

int sol = 12313123, ix, iy;

void probaj(int i, int j) {
	int v = abs(a[i] - a[j]);
	if (v < sol) {
		sol = v;
		ix = i;
		iy = j;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<n; i++)
		probaj(i, i+1);
	probaj(1, n);

	cout << ix << ' ' << iy << '\n';
}