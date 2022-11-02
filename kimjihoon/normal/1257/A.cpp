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
		int n, x, a, b; cin >> n >> x >> a >> b;
		cout << min(n - 1, abs(a - b) + x) << '\n';
	}
	return 0;
}