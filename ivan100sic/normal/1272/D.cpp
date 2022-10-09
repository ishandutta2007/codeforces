#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], l[200005], r[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	// self
	int str = 1, sol = 1;
	for (int i=1; i<n; i++) {
		if (a[i] > a[i-1]) {
			str++;
		} else {
			str = 1;
		}
		sol = max(sol, str);
	}

	l[0] = 1;
	for (int i=1; i<n; i++)
		l[i] = a[i] > a[i-1] ? l[i-1] + 1 : 1;

	r[n-1] = 1;
	for (int i=n-2; i>=0; i--)
		r[i] = a[i] < a[i+1] ? r[i+1] + 1 : 1;

	for (int i=1; i<n-1; i++) {
		if (a[i-1] < a[i+1]) {
			sol = max(sol, l[i-1] + r[i+1]);
		}
	}

	cout << sol << '\n';
}