// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[1000005];
basic_string<int> parovi[500005], e[1000005];
int v[1000005];

void dfs(int x) {
	for (int y : e[x]) {
		if (!v[y]) {
			v[y] = v[x] + 1;
			dfs(y);
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	if (n % 2 == 0) {
		cout << "First\n";
		for (int i=1; i<=2*n; i++) {
			cout << i%n+1 << " \n"[i == 2*n];
		}
		cout << flush;
		int x;
		cin >> x;
		return x;
	} else {
		cout << "Second\n" << flush;
		for (int i=1; i<=2*n; i++) {
			cin >> a[i];
			parovi[a[i]] += i;
		}

		for (int i=1; i<=n; i++) {
			int u = parovi[i][0], v = parovi[i][1];
			e[u] += v;
			e[v] += u;
		}

		for (int i=1; i<=n; i++) {
			e[i] += i+n;
			e[i+n] += i;
		}

		for (int i=1; i<=2*n; i++) {
			if (!v[i]) {
				v[i] = 1;
				dfs(i);
			}
		}

		basic_string<int> r[2];
		ll s[2] = {0, 0};
		for (int i=1; i<=2*n; i++) {
			r[v[i] % 2] += i;
			s[v[i] % 2] += i;
		}

		int j = !!(s[0] % (2*n));
		for (int i=0; i<n; i++) {
			cout << r[j][i] << " \n"[i == n-1];
		}
		cout << flush;
		int x;
		cin >> x;
		return x;
	}
}