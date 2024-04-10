#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[300005];

ll kv(ll x) {
	return x*x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll sol = 0;
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	for (int i=0; i<n/2; i++)
		sol += kv(a[i] + a[n-1-i]);
	cout << sol << '\n';
}