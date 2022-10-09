#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int f[200005];
int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		f[x]++;
	}

	for (int i=1; i<=n; i++) {
		if (f[i]) {
			if (!a[i-1] && !a[i])
				a[i+1] = 1;
		}
	}
	cout << count(a, a+n+2, 1) << ' ';
	memset(a, 0, sizeof a);
	for (int i=1; i<=n; i++) {
		while (f[i]--) {
			if (!a[i-1])
				a[i-1] = 1;
			else if (!a[i])
				a[i] = 1;
			else
				a[i+1] = 1;
		}
	}
	cout << count(a, a+n+2, 1) << '\n';
}