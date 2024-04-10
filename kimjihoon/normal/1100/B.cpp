#include <iostream>
using namespace std;

int c[100009], rc[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int r = 0, t = 1;
	for (int i = 0; i < m; i++) {
		int a; cin >> a;
		c[a]++; rc[c[a]]++;
		if (rc[t] >= n) {
			t++;
			cout << 1;
		}
		else
			cout << 0;
	}
	cout << '\n';
	return 0;
}