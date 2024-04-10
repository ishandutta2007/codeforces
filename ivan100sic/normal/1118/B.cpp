#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], e[200005], o[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		e[i] = e[i-1] + (i % 2 == 0 ? a[i] : 0);
		o[i] = o[i-1] + (i % 2 == 1 ? a[i] : 0);
	}

	int z = 0;
	for (int i=1; i<=n; i++) {
		int raz = e[i-1] - o[i-1] - (e[n] - e[i]) + (o[n] - o[i]);
		if (raz == 0)
			z++;
	}

	cout << z << '\n';
}