#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	vector<int> a = {1, 3, 15, 133, 2025, 37851, 1030367, 36362925};
	int p = n%2*a[n>>1];
	for (ll i=1; i<=n; i++)
		p = p*i%1000000007;
	cout << p << '\n';
}