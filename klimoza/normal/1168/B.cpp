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

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	string st;
	cin >> st;
	int n = st.size();
	vector<pair<int, int>> pref;
	for (int i = 0; i < n; i++) {
		for (int k = 1; k < 6; k++) {
			if (i - k < 0 || i + k >= n) break;
			if (st[i - k] == st[i] && st[i] == st[i + k]) {
				pref.push_back({ i - k, i + k });
				break;
			}
		}
	}
	sort(pref.begin(), pref.end());
	int mini = n;
	int ind = pref.size() - 1;
	ll ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (ind >= 0 && pref[ind].first >= i) {
			mini = min(mini, pref[ind--].second);
		}
		ans += n - mini;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}