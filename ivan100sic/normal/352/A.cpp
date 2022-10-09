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

	int a, b, n;
	cin >> n;
	a=b=0;
	while (n--) {
		int x;
		cin >> x;
		if (x == 0)
			a++;
		else
			b++;
	}
	if (b < 9) {
		if (a > 0) {
			cout << "0\n";
		} else {
			cout << "-1\n";
		}
	} else {
		if (a == 0) {
			cout << "-1\n";
		} else {
			cout << string(b/9*9, '5') << string(a, '0') << '\n';
		}
	}
}