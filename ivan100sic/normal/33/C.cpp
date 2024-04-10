#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, z, f, w;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z += a[i];
	}
	for (int i=1; i<=n; i++) {
		f += a[i];
		f = max(f, 0);
		w = max(w, f);
	}

	cout << 2*w-z << '\n';
}