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
		int s = 0;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			s += a;
		}
		if (s == n) cout << 0 << '\n';
		else if (s < n) cout << 1 << '\n';
		else cout << s - n << '\n';
	}
	return 0;	
}