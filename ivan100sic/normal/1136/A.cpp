#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int l[105], r[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> l[i] >> r[i];
	int x, z=0;
	cin >> x;
	for (int i=1; i<=n; i++) {
		if (r[i] >= x)
			z++;
	}
	cout << z << '\n';
}