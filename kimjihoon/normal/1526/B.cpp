#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		for (int i = 0; i <= 12 && n > 0 && n % 11 != 0; i++) 
			n -= 111;
		if (n >= 0 && n % 11 == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}