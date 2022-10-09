#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[3], d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> a[0] >> a[1] >> a[2] >> d;
	sort(a, a+3);
	cout << max(0ll, d-a[1]+a[0]) + max(0ll, d-a[2]+a[1]) << '\n';
}