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
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = -1;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

vector<int> sum[2];

int getsum(int k, int l, int r) {
	int res = sum[k][r];
	if (l) res -= sum[k][l - 1];
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
	int n;
	while (cin >> n) {
		sum[0].assign(n, 0);
		sum[1].assign(n, 0);

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum[--a[i]][i] = 1;
		}
		for (int i = 1; i < n; i++) {
			sum[0][i] += sum[0][i - 1];
			sum[1][i] += sum[1][i - 1];
		}
		vector<pair<int, int> > ans;
		for (int t = 1; t <= n; t++) {
			int cur = 0;
			int score0 = 0, score1 = 0, last = -1;

			while (cur < n) {
				int l = cur - 1, r = n;
				while (r - l > 1) {
					int m = (l + r) >> 1;
					if (getsum(0, cur, m) >= t || getsum(1, cur, m) >= t) {
						r = m;
					} else {
						l = m;
					}
				}
				if (r == n) {
					last = -1;
					break;
				}
				if (a[r] == 0) {
					score0++;
				} else {
					score1++;
				}
				last = a[r];
				cur = r + 1;
			}
			if (last == 0 && score0 > score1) {
				ans.push_back(make_pair(score0, t));
			}
			if (last == 1 && score1 > score0) {
				ans.push_back(make_pair(score1, t));
			}
		}
		sort(ans.begin(), ans.end());
		cout << ans.size() << endl;
		for (int i = 0; i < (int)ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
	}

    return 0;
}