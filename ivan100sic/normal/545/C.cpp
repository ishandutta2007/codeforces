#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int x[100005], h[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> x[i] >> h[i];

	// prvo obaramo u levo
	int sol = 1, last = x[1];
	for (int i=2; i<=n; i++) {
		if (x[i] - last > h[i]) {
			// samo ga obori u levo
			sol++;
			last = x[i];
		} else if (i == n || x[i+1] - x[i] > h[i]) {
			sol++;
			last = x[i] + h[i];
		} else {
			last = x[i];
		}
	}
	cout << sol << '\n';
}