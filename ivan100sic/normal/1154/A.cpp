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

	ll p[4];
	cin >> p[0] >> p[1] >> p[2] >> p[3];
	sort(p, p+4);
	cout << p[3]-p[0] << ' ' << p[3]-p[1] << ' ' << p[3]-p[2] << '\n';
}