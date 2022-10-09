#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int p[1005];
int c[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> p[i];

	for (int i=1; i<=n; i++) {
		fill(c+1, c+n+1, 0);
		int k = -1;
		for (int j=i; c[j]!=1; j=p[j])
			c[j]++, k=j;
		cout << p[k] << ' ';
	}
	cout << '\n';
}