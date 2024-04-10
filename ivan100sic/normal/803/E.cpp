#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, k;
string s;
bool d[1005][2005];
char p[1005][2005];

void reconstruct(int kr) {
	int x = n;
	string s;
	while (x > 0) {
		char dec = p[x][kr];
		s += dec;
		if (dec == 'L') {
			kr++;
		} else if (dec == 'W') {
			kr--;
		}
		x--;
	}
	reverse(s.begin(), s.end());
	cout << s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;

	s = string(" ") + s;

	d[0][k] = true;

	for (int i=1; i<=n; i++) {
		if (s[i] == 'W') {
			for (int j=1; j<=2*k; j++) {
				d[i][j] = d[i-1][j-1];
				p[i][j] = 'W';
			}
		} else if (s[i] == 'L') {
			for (int j=0; j<2*k; j++) {
				d[i][j] = d[i-1][j+1];
				p[i][j] = 'L';
			}
		} else if (s[i] == 'D') {
			for (int j=0; j<=2*k; j++) {
				d[i][j] = d[i-1][j];
				p[i][j] = 'D';
			}
		} else {
			for (int j=0; j<=2*k; j++) {
				d[i][j] = d[i-1][j];
				if (d[i-1][j]) {
					p[i][j] = 'D';
				}
				if (j > 0) {
					d[i][j] |= d[i-1][j-1];
					if (d[i-1][j-1]) {
						p[i][j] = 'W';
					}
				}
				if (j < 2*k) {
					d[i][j] |= d[i-1][j+1];
					if (d[i-1][j+1]) {
						p[i][j] = 'L';
					}
				}
			}
		}
		if (i < n) {
			d[i][0] = false;
			d[i][2*k] = false;
		}
	}

	if (d[n][0]) {
		reconstruct(0);
	} else if (d[n][2*k]) {
		reconstruct(2*k);
	} else {
		cout << "NO";
	}
}