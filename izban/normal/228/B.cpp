#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define ll long long


const int maxn = 101;

int n[2], m[2], ans = -1, ansx=-1, ansy=-1;
char a[maxn][maxn][2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	for (int k = 0; k < 2; k++) {
		cin >> n[k] >> m[k];
		for (int i = 0; i < n[k]; i++)
			for (int j = 0; j < m[k]; j++)
				cin >> a[i][j][k];
	}

	for (int x = -50; x <= 50; x++) {
		for (int y = -50; y <= 50; y++) {
			ll sum = 0;
			for (int i = 0; i < n[0] && i + x < n[1]; i++)
				for (int j = 0; j < m[0] && j + y < m[1]; j++)
					if (i+x >= 0 && j+y >= 0)
						sum += (a[i][j][0]-'0') * (a[i+x][j+y][1]-'0');
			if (ans < sum) {
				ans = sum;
				ansx = x; ansy = y;
			}
		}
	}

	cout << ansx << " " << ansy;

	return 0;
}