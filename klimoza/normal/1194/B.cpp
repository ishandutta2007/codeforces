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

#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9+ 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<string> st(n);
		for (string& a : st) cin >> a;
		vector<int> cntn(n);
		vector<int> cntm(m);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (st[i][j] == '.') {
					cntn[i]++;
					cntm[j]++;
				}
			}
		}
		int ans = inf0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				ans = min(ans, cntn[i] + cntm[j] - (st[i][j] == '.'));
			}
		}
		cout << ans << endl;
	}
	return 0;
}