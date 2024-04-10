#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x, y, z, t1, t2, t3; cin >> x >> y >> z >> t1 >> t2 >> t3;
	if (abs(x - z) * t2 + abs(x - y) * t2 + t3 * 3 <= abs(x - y) * t1)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	return 0;
}