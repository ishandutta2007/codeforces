#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = 128;

int dp[MAXN][MAXN][MAXN][2];

int f(int k, int i, int j) {
	int my = -1;
	if (k == 1) {
		my = j * 2 >= i;
	} else

	if (k % 2 == 0) {
		if (i == k) {
			my = j % 2;
		} else {
			my = i % 2 == 1 && j >= (i - k + 1) / 2 && j <= i - (i - k + 1) / 2;
		}
	} else
	
	if (k % 2 == 1) {
		if (i == k) {
			my = j % 2;
		} else {
			if ((i - k) % 2 == 1) {
				my = j >= (i - k + 1) / 2;
			} else {
				my = j >= i - (i - k) / 2;
			}
		}
	}

	return my;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	
	int i, k;
	while (cin >> i >> k) {
		int j = 0;
		for (int o = 0; o < i; o++) {
			int x;
			cin >> x;
			j += x % 2;
		}
		cout << (f(k, i, j) ? "Stannis" : "Daenerys") << endl;
	}
	return 0;
	/*
	memset(dp, -1, sizeof(dp));

	int O = 20;
	for (int k = 1; k <= O; k++) {
		for (int i = 0; i <= k; i++) {
			for (int o = 0; o < 2; o++) {
				dp[k][k][i][o] = (o ^ i) % 2;
			}
		}

		for (int i = k; i <= O; i++) {
			for (int j = 0; j <= i; j++) {
				if (i > k) 
				for (int o = 0; o < 2; o++) {
					int can0 = 0;
					if (j) can0 |= dp[k][i - 1][j - 1][o ^ 1] == 0;
					if (j < i) can0 |= dp[k][i - 1][j][o ^ 1] == 0;
					dp[k][i][j][o] = can0;
				}
				//cout << "{" << dp[k][i][j][0] << ", " << dp[k][i][j][1] << "} ";
				int my = -1;
				my = f(k, i, j);

				if (my != -1) {
					assert(my == dp[k][i][j][0]);
					cout << "x" << " ";
				}
				else cout << dp[k][i][j][0] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}*/
	
	return 0;
}