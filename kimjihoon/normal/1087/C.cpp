#include <iostream>
#include <cmath>
using namespace std;

int px[3], py[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	for (int i = 0; i < 3; i++)
		cin >> px[i] >> py[i];
	int mn = 1000000000, rx = -1, ry = -1;
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1000; j++) {
			int d = 0;
			for (int k = 0; k < 3; k++)
				d += abs(i - py[k]) + abs(j - px[k]);
			d++;
			if (mn > d) {
				mn = d;
				rx = j; ry = i;
			}
		}
	cout << mn << '\n';
	cout << rx << " " << ry << '\n';
	for (int i = 0; i < 3; i++) {
		int tx = rx, ty = ry;
		while (tx != px[i] || ty != py[i]) {
			if (tx < px[i]) tx++;
			else if (tx > px[i]) tx--;
			else if (ty < py[i]) ty++;
			else if (ty > py[i]) ty--;
			cout << tx << " " << ty << '\n';
		}
	}
	return 0;
}