#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<vector<char>> h(50);
	int total = a + c + d;
	bool on = false;
	char col;
	int ans = 0;
	for (int i = 0; i < 50; i++) {
		if (total + b == 0) {
			ans = i;
			break;
		}
		if (!on) {
			if (i % 2 == 0) {
				h[i].resize(50);
				for (int j = 0; j < 50; j++) {
					if (j == 0 or total == 1) {
						h[i][j] = 'B';
					}
					else {
						if (a > 0 and h[i][j - 1] != 'A') {
							h[i][j] = 'A';
							a--;
							total--;
						}
						else if (c > 0 and h[i][j - 1] != 'C') {
							h[i][j] = 'C';
							c--;
							total--;
						}
						else if (d > 0 and h[i][j - 1] != 'D') {
							h[i][j] = 'D';
							d--;
							total--;
						}
						else {
							h[i][j] = 'B';
						}
					}
				}
			}
			else {
				h[i].assign(50, 'B');
				if (total == 1) {
					if (a == 1) col = 'A';
					else if (c == 1) col = 'C';
					else col = 'D';
					on = true;
					b--;
				}
			}
		}
		else {
			total = 0;
			if (i % 2 == 0) {
				h[i].assign(50, col);
			}
			else {
				h[i].resize(50);
				for (int j = 0; j < 50; j++) {
					if (b > 0 and j % 2 == 0) {
						h[i][j] = 'B';
						b--;
					}
					else {
						h[i][j] = col;
					}
				}
			}
		}
	}
	cout << ans << " " << 50 << "\n";
	for (int i = 0; i < ans; i++) {
		for (int j = 0; j < 50; j++) {
			cout << h[i][j];
		}
		cout << "\n";
	}
	//system("pause");
	return 0;
}