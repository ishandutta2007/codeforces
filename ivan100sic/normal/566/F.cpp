#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[1000005], d[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	int sol = 0;

	for (int i=1; i<=1000000; i++) {
		if (c[i]) {
			sol = max(sol, d[i] + 1);
			for (int j=i+i; j<=1000000; j+=i)
				if (c[j])
					d[j] = max(d[j], d[i]+1);
		}
	}
	cout << sol << '\n';
}