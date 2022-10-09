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

	ll x;
	cin >> x;
	cout << x / lcm(2, lcm(3, lcm(4, lcm(5, lcm(6, lcm(7, lcm(8, lcm(9, 10)))))))) << '\n';
}