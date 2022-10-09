#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, c;
int a[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	int sol = 0;
	for (int i=1; i<n; i++)
		sol = max(sol, a[i] - a[i+1] - c);
	cout << sol << '\n';
}