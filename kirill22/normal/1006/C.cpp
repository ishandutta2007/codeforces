#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int i = 0, j = n+1;
	ll zi = 0, zj = 0, solidx = 0;
	while (i < j) {
		if (zi < zj)
			zi += a[++i];
		else if (zi > zj)
			zj += a[--j];
		else {
			solidx = i;
			zi += a[++i];
			zj += a[--j];
		}
	}
	
	cout << accumulate(a+1, a+solidx+1, 0ll); // here
}