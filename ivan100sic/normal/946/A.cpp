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

	int n, x=0, y=0;
	cin >> n;
	while (n--) {
		int a;
		cin >> a;
		(a <= 0 ? x : y) += a;
	}
	cout << y-x << '\n';
}