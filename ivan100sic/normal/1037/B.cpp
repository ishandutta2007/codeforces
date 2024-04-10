#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[200005], s, n;
ll sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	int h = n/2;
	for (int i=0; i<h; i++)
		sol += max(0, a[i] - s);
	for (int i=h+1; i<n; i++)
		sol += max(0, s - a[i]);
	sol += abs(a[h] - s);
	cout << sol << '\n';
}