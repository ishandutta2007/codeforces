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

	ll n, m, s;
	cin >> n >> m >> s;
	cout << ((n+s-1)%s+1) * ((m+s-1)%s+1) * ((n+s-1)/s) * ((m+s-1)/s) << '\n';
}