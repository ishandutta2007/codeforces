#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 998244353;

int n;
vector<vector<int>> g;

void find_clique(int l, int r, vector<int> &dp) {
	if (l == r) return;
	int sz = r - l;
	for (int i = 0; i < sz; i++) dp[1 << i] = 1;
	if (sz == 1) return;
	int m1 = (l + r) / 2 - l;
	int m2 = r - (l + r) / 2;
	vector<int> dp1(1 << m1), dp2(1 << m2);
	find_clique(l, (l + r) / 2, dp1);
	find_clique((l + r) / 2, r, dp2);
	for (int i = 1; i < (1 << sz); i++) {
		for (int j = 0; j < sz; j++) dp[i] = max(dp[i], dp[i ^ (1 << j)]);
		int t1 = 0, t2 = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int j = 0; j < sz; j++) {
			if (!((1 << j) & i)) continue;
			if (j < m1) {
				t1 += (1 << j);
			}
			else {
				t2 += (1 << (j - m1));
			}
		}
		//cout << i << " " << dp[i] << " " << l << " " << r << " " << t1 << "  " << t2 << " " << dp1[t1] << " " << dp2[t2] << endl;
		bool fl = true;
		for (int j = 0; j < m1; j++) {
			for (int k = 0; k < m2; k++) {
				if (((1 << j) & t1) && ((1 << k) & t2) && !g[j + l][k + l + m1]) {
					fl = false;
					break;
				}
			}
		}
		if (fl) dp[i] = max(dp[i], dp1[t1] + dp2[t2]);
	}
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
	int k;
	cin >> n >> k;
	int t1, t2;
	g.assign(n, vector<int>(n));
	/*while (k--) {
		cin >> t1 >> t2; t1--; t2--;
		g[t1][t2] = 1;
		g[t2][t1] = 1;
	}*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	int m1 = n / 2;
	int m2 = n - n / 2;
	vector<int> dp1(1 << m1), dp2(1 << m2);
	find_clique(0, n / 2, dp1);
	find_clique(n / 2, n, dp2);
	int maxi = 1;
	for (int i = 0; i < (1 << m1); i++) {
		int t = 0;
		for (int j = n / 2; j < n; j++) {
			bool fl = true;
			for (int k = 0; k < n / 2; k++) {
				if (((1 << k) & i) && (!g[k][j])) {
					fl = false;
					break;
				}
			}
			if (fl) {
				t += (1 << (j - n / 2));
			}
		}
		maxi = max(maxi, dp1[i] + dp2[t]);
	}
	/*vector<int> dp(1 << n);
	find_clique(0, n, dp);
	int maxi = 0;
	for (int i : dp) maxi = max(maxi, i);*/
	cout << (double)k * k * (double)(maxi - 1) / (2 * (double)maxi) << endl;
	//system("pause");
	return 0;
}