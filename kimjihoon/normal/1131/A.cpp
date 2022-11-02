#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int w1, h1, w2, h2;
	cin >> w1 >> h1 >> w2 >> h2;
	cout << 2 * (h1 + w1 + h2) + 4 << '\n';
	return 0;
}