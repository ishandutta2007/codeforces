#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
	int q;
	cin >> q;
	ll n, a, b;
	for (int k = 0; k < q; k++) {
		cin >> n >> a >> b;
		if (2 * a < b) cout << n * a << endl;
		else cout << (n / 2) * b + (n % 2) * a << endl;
	}
	return 0;
}