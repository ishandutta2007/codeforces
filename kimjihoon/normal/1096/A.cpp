#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int l, r; cin >> l >> r;
		cout << l << " " << l * 2 << '\n';
	}
	return 0;
}