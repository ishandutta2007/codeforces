#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int w, h, u1, d1, u2, d2; cin >> w >> h >> u1 >> d1 >> u2 >> d2;
	for (int i = h; i >= 1; i--) {
		w += i;
		if (i == d1) w -= u1;
		if (i == d2) w -= u2;
		if (w < 0) w = 0;
	}
	cout << w << '\n';
	return 0;
}