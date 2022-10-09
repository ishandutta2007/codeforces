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

	int n, a, b, c;
	cin >> n >> a >> b >> c;
	if (n == 1)
		cout << "0\n";
	else if (min(a, b) <= c)
		cout << min(a, b) * (n-1) << '\n';
	else
		cout << min(a, b) + c * (n-2) << '\n';
}