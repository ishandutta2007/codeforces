#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	int n;
	cin >> n;
	if (n % 2) cout << "0\n";
	else {
		int ans = n / 4;
		if (n % 4 == 0) ans--;
		cout << ans << '\n';
	}
}