#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int k; cin >> k; k += 2000;
	cout << 2000 << '\n';
	cout << -1 << " ";
	for (int i = 0; i < 1999; i++) {
		if (k > 1000000) {
			cout << 1000000 << " ";
			k -= 1000000;
		}
		else {
			cout << k << " ";
			k = 0;
		}
	}
	cout << '\n';
	return 0;
}