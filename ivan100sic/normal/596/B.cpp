#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	ll w = 0;
	for (int i=1; i<=n; i++)
		w += abs(a[i] - a[i-1]);
	cout << w << '\n';
}