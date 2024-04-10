#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	ll z = accumulate(a, a+n, 0ll);
	ll y = *max_element(a, a+n);

	cout << (z % 2 == 0 && 2*y <= z ? "YES\n" : "NO\n");
}