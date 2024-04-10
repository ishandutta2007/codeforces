// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int u[100005], v[100005];
basic_string<int> e[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> u[i] >> v[i];
		e[u[i]] += i;
		e[v[i]] += i;
	}

	cout << n-1 << '\n';
	for (int i=1; i<n; i++) {
		cout << "2 " << u[i] << ' ' << v[i] << '\n';
	}

	for (int i=1; i<=n; i++) {
		for (int j=0; j<(int)e[i].size()-1; j++) {
			cout << e[i][j] << ' ' << e[i][j+1] << '\n';
		}
	}
}