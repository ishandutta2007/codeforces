#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[200005], z[200005];
ll d1[200005];
ll d2[200005];
ll q1[200005], q2[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	reverse(a, a+n);
	for (int i=0; i<n; i++) {
		z[i+1] = z[i] + a[i];
	}

	d1[1] = d2[1] = 0;
	for (int i=2; i<=n; i++) {
		d1[i] = q2[i-2] + z[n];
		d2[i] = q1[i-2] - z[n];
		q1[i-1] = min(q1[i-2], d1[i]+z[i-1]);
		q2[i-1] = max(q2[i-2], d2[i]-z[i-1]);
	}

	cout << d1[n] << '\n';
}