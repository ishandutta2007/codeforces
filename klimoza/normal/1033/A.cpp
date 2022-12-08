#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	vector<vector<int>> field(n + 1);
	for (int i = 1; i <= n; i++) {
		field[i].resize(n + 1);
		for (int j = 1; j <= n; j++) {
			if (j == ay || i == ax) {
				field[i][j] = 1;
			}
			else {
				field[i][j] = 0;
			}
		}
	}
	bool fl = false;
	for (int i = min(bx, cx); i <= max(bx, cx); i++) {
		if (field[i][by] == 1 || field[i][cy] == 1) {
			fl = true;
			break;
		}
	}
	for (int i = min(by, cy); i <= max(by, cy); i++) {
		if (field[bx][i] == 1 || field[cx][i] == 1) {
			fl = true;
			break;
		}
	}
	if (fl) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
	//system("pause");
	return 0;
}