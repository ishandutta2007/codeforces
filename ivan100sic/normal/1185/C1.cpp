#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int c[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		int rem = m-x, pass = 0;
		for (int j=1; j<=100; j++) {
			int delta = min(rem/j, c[j]);
			rem -= delta*j;
			pass += delta;
		}
		cout << i - pass << ' ';
		c[x]++;
	}
	cout << '\n';
}