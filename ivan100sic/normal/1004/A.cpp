#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, d;
ll a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> d;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	sort(a+1, a+n+1);

	ll sol = 0;
	sol += 2;

	for (int i=1; i<n; i++) {
		if (a[i+1] - a[i] == 2*d)
			sol++;
		else if (a[i+1] - a[i] > 2*d)
			sol += 2;
	}

	cout << sol;
}