#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int a, b; cin >> a >> b;
		if (gcd(a, b) == 1) cout << "Finite" << '\n';
		else cout << "Infinite" << '\n';
	}
	return 0;
}