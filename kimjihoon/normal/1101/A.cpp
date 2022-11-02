#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r, d; cin >> l >> r >> d;
		if (d < l || r < d) cout << d << '\n';
		else cout << (r / d + 1) * d << '\n';
	}
	return 0;
}