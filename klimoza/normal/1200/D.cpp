#define _CRT_SECURE_NO_WARNINGS
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
#define fi first
#define se second

using namespace std;

typedef long long ll;

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
const double eps = 1e-6;
const ll mod1 = 998244353;
const ll mod2 = 777777773;
const ll P1 = 239;
const ll P2 = 241;

mt19937 mrand(random_device{} ());

bool in(pair<int, int> ff, int x) {
	return ff.first <= x && x <= ff.second;
}

signed main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout.precision(15);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	

	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> lr(n, { -1, n });
	vector<pair<int, int>> ud(n, { -1, n });
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			if (c == 'B') {
				if (lr[i] == make_pair(-1, n))
				lr[i] = make_pair(0, n - 1);
				if(ud[j] == make_pair(-1, n))
				ud[j] = make_pair(0, n - 1);
				lr[i].first = max(lr[i].first, j - k + 1);
				lr[i].second = min(lr[i].second, j);
				ud[j].first = max(ud[j].first, i - k + 1);
				ud[j].second = min(ud[j].second, i);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (lr[i] == make_pair(-1, n)) ans++;
		if (ud[i] == make_pair(-1, n)) ans++;
	}
	for (int i = 0; i < n; i++) {
		if (lr[i].first > lr[i].second) lr[i] = make_pair(-1, n);
		if (ud[i].first > ud[i].second) ud[i] = make_pair(-1, n);
		//cout << lr[i].first << " " << lr[i].second << " blay\n";
	}
	int normal = ans;
	for (int i = 0; i < n - k + 1; i++) {
		int cur = normal;
		vector<pair<int, int>> cc;
		int id = 0;
		//cout << i << endl;
		for (int j = 0; j < n - k + 1; j++) {
			if (j == 0) {
				for (int jj = 0; jj < k; jj++) {
					if (ud[jj] == make_pair(-1, n)) continue;
					cur += in(ud[jj], i);
				}
				for (int jj = i; jj < i + k; jj++) {
					if (lr[jj] == make_pair(-1, n)) continue;
					cc.push_back({ lr[jj].first, 1 });
					cc.push_back({ lr[jj].second +1, -1 });
				}
				sort(cc.begin(), cc.end());
			}
			while (id != size(cc) && cc[id].first == j) {
				//cout << cc[id].first << " " << cc[id].second << " looll\n";
				cur += cc[id++].second;
			}
			//cout << cur << endl;
			if (j != 0) {
				if (ud[j - 1] != make_pair(-1, n))
				cur -= in(ud[j - 1], i);
				if (ud[j + k - 1] != make_pair(-1, n))
				cur += in(ud[j + k - 1], i);
			}
			//cout << i << "  poooo " << j << " " << cur << endl;
			ans = max(ans, cur);
		}
	}
	cout << ans << endl;
	return 0;
}