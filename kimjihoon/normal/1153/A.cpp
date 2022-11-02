#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, t; cin >> n >> t;
	int a = 1000000000, ai = 0;
	for (int i = 1; i <= n; i++) {
		int s, d; cin >> s >> d;
		int c = t;
		while (c < s || (c - s) % d != 0) {
			c++;
		}
		if (a > c) {
			a = c; ai = i;
		}
	}
	cout << ai << '\n';
	return 0;
}