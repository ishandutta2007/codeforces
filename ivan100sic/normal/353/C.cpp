#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], z[100005];
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (i)
			z[i] = z[i-1];
		z[i] += a[i];
	}

	cin >> s;

	int sol = 0, tren = 0;

	for (int i=n-1; i>=0; i--) {
		if (s[i] == '1') {
			// stavi nulu
			sol = max(sol, tren + (i ? z[i-1] : 0));
			tren += a[i];
		}
	}

	sol = max(sol, tren);
	cout << sol << '\n';
}