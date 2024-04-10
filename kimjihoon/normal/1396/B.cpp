#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int s = 0, mx = 0;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			s += a;
			mx = max(mx, a);
		}
		if (mx <= s - mx && s % 2 == 0) cout << "HL" << '\n';
		else cout << "T" << '\n';
	}	
	return 0;
}