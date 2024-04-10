#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005], t[100005], z[100005], outdeg[100005];
basic_string<int> sol;

int solve(int x) {
	if (z[x] != -1)
		return z[x];
	if (outdeg[x] >= 2)
		return z[x] = 0;
	if (a[x] == 0)
		return z[x] = 1;
	return z[x] = solve(a[x]) + 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> t[i];
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		outdeg[a[i]]++;
	}
	
	fill(z+1, z+n+1, -1);
	int y=-1, j=-1;
	for (int i=1; i<=n; i++) {
		if (t[i]) {
			if (solve(i) > y) {
				y = solve(i);
				j = i;
			}
		}
	}
	for (int i=0, x=j; i<y; i++,x=a[x])
		sol += x;
	reverse(sol.begin(), sol.end());
	cout << y << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}