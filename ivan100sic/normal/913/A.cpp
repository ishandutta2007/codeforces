#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	long long n, m;
	cin >> n >> m;

	if (n > 30) {
		cout << m;
	} else {
		cout << (m % (1ll << n));
	}
}