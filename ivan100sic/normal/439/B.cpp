#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	ll z = 0;
	for (int i=0; i<n; i++)
		z += a[i] * 1ll * max(1, x-i);
	cout << z << '\n';
}