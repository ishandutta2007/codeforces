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
		bool f = false;
		if (n % 2 == 0) {
			f = true;
			int p = 0;
			while (n % 2 == 0) {
				n /= 2; p++;
			}
			if ((p & 1) && n == 1) f = false;
		}
		if (f) cout << "Alice\n";
		else cout << "Bob\n";
	}
	return 0;	
}