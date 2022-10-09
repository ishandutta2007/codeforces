// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005];
int u[100005], v[100005], w[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		cin >> u[i] >> v[i];
		e[u[i]] += i;
		e[v[i]] += i;
		w[i] = -1;
	}

	int a = 0;
	for (int i=1; i<=n; i++) {
		int ok = 0;
		if (e[i].size() >= 3) {
			ok = 1;
			for (int j : e[i])
				w[j] = a++;
		}
		if (ok)
			break;
	}

	for (int i=1; i<n; i++) {
		if (w[i] == -1)
			w[i] = a++;
		cout << w[i] << '\n';
	}
}

// I will still practice daily...