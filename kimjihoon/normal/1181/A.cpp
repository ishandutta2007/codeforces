#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	long long x, y, z;
	cin >> x >> y >> z;
	if ((x % z) + (y % z) < z) cout << x / z + y / z << " " << 0 << '\n';
	else
		cout << x / z + y / z + 1 << " " << z - max(x % z, y % z) << '\n';
	return 0;
}