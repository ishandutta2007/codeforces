#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], b[100005];
basic_string<int> e[100005];

int ctot[205];

int get_stat(int x) {
	int z = 0;
	for (int i=1; i<=200; i++) {
		int y = min(ctot[i], x);
		x -= y;
		z += y * i;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	for (int i=0; i<n; i++)
		cin >> b[i];

	for (int i=0; i<n; i++)
		e[a[i]] += b[i];

	int sol = 1123123123;

	int veci_tot = 0;
	int veci_br = 0;

	for (int i=0; i<n; i++)
		ctot[b[i]]++;

	for (int x=100000; x>=1; x--) {
		int k = e[x].size();

		for (int y : e[x]) {
			veci_br += 1;
			veci_tot += y;
			ctot[y] -= 1;
		}

		if (2*k > n)
			sol = 0;
		else {
			// ukloni sve vece
			int rm = max(0, n - (k-1) - veci_br);
			int z = get_stat(rm);
			sol = min(sol, veci_tot + z - accumulate(e[x].begin(), e[x].end(), 0));
		}
	}

	cout << sol << '\n';
}