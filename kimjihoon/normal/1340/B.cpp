#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int d[2009][2009], rp[2009][2009];
string s[2009];
string p[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, kp; cin >> n >> kp;
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 0; i <= kp; i++)
		d[n + 1][i] = -1;
	d[n + 1][0] = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= kp; j++)
			d[i][j] = -1;
		for (int j = 0; j < 10; j++) {
			int r = 0;
			for (int k = 0; k < 7; k++) {
				if (p[j][k] == '0' && s[i][k] == '1') {
					r = -1;
					break;
				}
				else if (p[j][k] == '1' && s[i][k] == '0')
					r++;
			}
			if (r == -1) continue;
			for (int k = r; k <= kp; k++) {
				if (d[i + 1][k - r] != -1) {
					d[i][k] = j;
					rp[i][k] = k - r;
				}
			}
		}
	}
	if (d[1][kp] == -1) {
		cout << -1 << '\n';
		return 0;
	}
	int di = kp;
	for (int i = 1; i <= n; i++) {
		cout << d[i][kp];
		kp = rp[i][kp];
	}
	cout << '\n';
	return 0;
}