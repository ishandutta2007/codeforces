#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	if (n == 1) {
		cout << "1\n";
		return 0;
	}

	int sol = 1, streak = 1;
	for (int i=2; i<=n; i++) {
		if (a[i] != a[i-1])
			streak++;
		else
			streak = 1;
		sol = max(sol, streak);
	}

	cout << sol << '\n';

}