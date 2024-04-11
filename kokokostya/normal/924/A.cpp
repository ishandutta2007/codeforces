
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <functional>
#include <cstring>
//#include "optimization.h"

using namespace std;

typedef long long ll;
const ll md = 1e9 + 7;

int main() {
    iostream::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n, m;
	cin >> n >> m;

	vector<vector<int>> t(n, vector<int>(m, 0));
	vector<vector<int>> T(m, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			t[i][j] = T[j][i] = c == '#';
		}
	}
	bool ch = 1;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			bool x = 0;
			for (int k = 0; k < m; k++) {
				x |= t[i][k] && t[j][k];
			}
			ch &= !x || (t[i] == t[j]);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			bool x = 0;
			for (int k = 0; k < n; k++) {
				x |= T[i][k] && T[j][k];
			}
			ch &= !x || (T[i] == T[j]);
		}
	}
	cout << (ch ? "Yes\n" : "No\n");

    return 0;
}