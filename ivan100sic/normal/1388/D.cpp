// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
ll a[200005];
int b[200005];
basic_string<int> e[200005], rem, sol;
ll skor;

void dfs(int x) {
	for (int y : e[x]) {
		dfs(y);
	}
	if (a[x] >= 0) {
		if (b[x] != -1) {
			a[b[x]] += a[x];
		}
		skor += a[x];
		sol += x;
	} else {
		rem += x;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
		if (b[i] != -1) {
			e[b[i]] += i;
		}
	}

	for (int i=1; i<=n; i++) {
		if (b[i] == -1) {
			dfs(i);
		}
	}

	reverse(begin(rem), end(rem));

	for (int x : rem) {
		sol += x;
		skor += a[x];
	}

	cout << skor << '\n';
	for (int x : sol) cout << x << ' ';
	cout << '\n';
}