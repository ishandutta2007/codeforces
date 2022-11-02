#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int x, y; cin >> x >> y;
		if ((x == 1 && y > 1) || (x <= 3 && y > 3)) cout << "NO" << '\n';
		else cout << "YES" << '\n';
	}
	return 0;
}