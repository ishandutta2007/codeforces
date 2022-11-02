#include <iostream>
#include <algorithm>
using namespace std;

int x, y, x2, y2;

int bs0(int s, int e)
{
	int md = (s + e) / 2;
	if (s >= e) return md;
	cout << "? " << 1 << " " << 1 << " " << md << " " << x << endl;
	int t; cin >> t;
	if (t % 2 == 1) return bs0(s, md);
	else return bs0(md + 1, e);
}

int bs1(int s, int e)
{
	int md = (s + e) / 2;
	if (s >= e) return md;
	cout << "? " << 1 << " " << 1 << " " << y << " " << md << endl;
	int t; cin >> t;
	if (t % 2 == 1) return bs1(s, md);
	else return bs1(md + 1, e);
}

int main()
{
	int n; cin >> n;
	int f = 0;
	for (int i = 1; i <= n; i++) {
		cout << "? " << 1 << " " << 1 << " " << n << " " << i << endl;
		int t; cin >> t;
		if (f == 0 && t % 2 == 1) {
			x = i; f = 1;
		}
		if (f == 1 && t % 2 == 0) {
			x2 = i; break;
		}
	}
	f = 0;
	for (int i = 1; i <= n; i++) {
		cout << "? " << 1 << " " << 1 << " " << i << " " << n << endl;
		int t; cin >> t;
		if (f == 0 && t % 2 == 1) {
			y = i; f = 1;
		}
		if (f == 1 && t % 2 == 0) {
			y2 = i; break;
		}
	}
	if (x == 0) {
		int p = bs1(1, n);
		x = x2 = p;
	}
	else if (y == 0) {
		int p = bs0(1, n);
		y = y2 = p;
	}
	else {
		cout << "? " << 1 << " " << 1 << " " << y << " " << x << endl;
		int t; cin >> t;
		if (t % 2 == 0)
			swap(x, x2);
	}
	cout << "! " << y << " " << x << " " << y2 << " " << x2 << endl;
	return 0;
}