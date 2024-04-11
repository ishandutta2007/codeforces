#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <math.h>

using namespace std;


const int N = 222;

vector<int> g[N];
int W[N], d[N], pos[N];
vector<int> ords[3];
int D[N];
int n;

int calc(int x) {
	int ans = 0, k = 0;
	memcpy(D, d, sizeof(d));

	while (k < n) {
		bool cool = false;
		for (int i = 0; i < ords[x].size(); ++i) {
			int c = ords[x][i];
			if (D[c] == 0) {
				++k;
				D[c] = -1;
				for (int j = 0; j < g[c].size(); ++j) {
					--D[ g[c][j] ];
					cool = true;
				}
			}
		}

		if (!cool) {
			x = (x + 1) % 3;
			if (k == n) return ans + n;
			++ans;
		}
	}
	return ans + n;
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);

	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> W[i];
		W[i]--;
		ords[W[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		d[i] = k;
		while (k--) {
			int x; cin >> x; --x;
			g[x].push_back(i);
		}
	}

	int ans = 1e9;
	for (int i = 0; i < 3; ++i)
		ans = min(ans, calc(i));
	cout << ans << endl;

	return 0;
}