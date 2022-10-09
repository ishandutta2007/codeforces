#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[1505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	int o = 0;
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			if (a[i] > a[j])
				o ^= 1;
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		int w = r-l+1;
		if (w*(w-1) / 2 % 2)
			o ^= 1;
		cout << (o ? "odd\n" : "even\n");
	}
}