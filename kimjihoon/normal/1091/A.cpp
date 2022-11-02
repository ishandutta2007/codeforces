#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int a, b, c; cin >> a >> b >> c;
	cout << min(a, min(b - 1, c - 2)) * 3 + 3 << '\n';
	return 0;
}