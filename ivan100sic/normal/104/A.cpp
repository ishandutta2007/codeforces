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

	int n;
	cin >> n;
	if (n <= 10 || n > 21) {
		cout << 0;
	} else if (n < 20 || n == 21) {
		cout << 4;
	} else {
		cout << 15;
	}
}