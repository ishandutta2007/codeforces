#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);
		if (a + b < c) cout << a + b << '\n';
		else cout << (a + b + c) / 2 << '\n';
	}
	return 0;
}