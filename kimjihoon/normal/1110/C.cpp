#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);	
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int a; cin >> a;
		bool f = true;
		int c = 0, ta = a;
		while (ta) {
			if (ta % 2 == 0) f = false;
			c++; ta /= 2;
		}
		if (f) {
			int ans = 1;
			for (int j = 2; j * j <= a; j++)
				if (a % j == 0) {
					ans = a / j;
					break;
				}
			cout << ans << '\n';
		}
		else
			cout << (1 << c) - 1 << '\n';
	}
	return 0;
}