#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	string s;
	cin >> s;

	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {

			vector<vector<int>> dist(10, vector<int>(10, 10000));

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int a = 0; a < 10; a++) {
						for (int b = 0; b < 10; b++) {
							if (a + b == 0) {
								continue;
							}
							if ((i + a * x + b * y) % 10 == j) {
								dist[i][j] = min(dist[i][j], a + b - 1);
							}
						}
					}
				}
			}

			int ans = 0;
			bool can = true;

			for (int i = 0; i < s.size() - 1; i++) {
				if (dist[s[i] - '0'][s[i + 1] - '0'] == 10000) {
					can = false;
				}

				ans += dist[s[i] - '0'][s[i + 1] - '0'];
			}
			if (can) {
				cout << ans << " ";
			} else {
				cout << -1 << " ";
			}
		}
		cout << endl;
	}
}