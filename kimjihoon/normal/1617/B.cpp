#include <iostream>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
	if (!b) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int n; cin >> n;
		int t = 2;
		while (gcd(t, n - 1) != 1)
			t++;
		cout << t << " " << n - 1 - t << " " << 1 << '\n';
	}
	return 0;
}