#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, k;
	cin >> n >> k;

	ll r = (2*n + k - 1) / k;
	ll g = (5*n + k - 1) / k;
	ll b = (8*n + k - 1) / k;

	cout << r + g + b << '\n';
}