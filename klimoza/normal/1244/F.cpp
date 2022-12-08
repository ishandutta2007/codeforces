#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

void solve();
void scan();

signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

void pr(int i) {
	if (i == 0) cout << 'W';
	else cout << 'B';
}

int n;

bool bet(int l, int i, int r) {
	if (l > r) r += n;
	if (i < l) i += n;
	if (l <= i && i <= r) return true;
	return false;
}

int md(int i) {
	if (i < 0) return i + n;
	if (i >= 0) return i % n;
}

void solve() {
	int k;
	cin >> n >> k;
	vector<int> ans(n);
	string st; cin >> st;
	for (int i = 0; i < n; i++) {
		if (st[i] == 'W') ans[i] = 0;
		else ans[i] = 1;
	}
	vector<bool> isStatic(n, false);
	if (ans[0] == ans.back() || ans[0] == ans[1]) isStatic[0] = true;
	for (int i = 1; i < n - 1; i++) {
		if (ans[i] == ans[i + 1] || ans[i] == ans[i - 1]) isStatic[i] = true;
	}
	if (ans.back() == ans[0] || ans.back() == ans[ans.size() - 2]) isStatic[n - 1] = true;
	vector<pair<pair<int, int>, int>> col;
	vector<int> nxt(n, -1);
	vector<int> prv(n, -1);
	int cur = -1;
	int bb = -1;
	for (int i = 0; i < n; i++) {
		if (isStatic[i]) {
			if (cur == -1) {
				bb = cur = i;
			}
			else {
				nxt[cur] = i;
				prv[i] = cur;
			}
			cur = i;
		}
	}
	if (bb != -1) {
		nxt[cur] = bb;
		prv[bb] = cur;
	}
	/*for (int i = 0; i < n; i++) {
		cout << i << " " << nxt[i] << " " << prv[i] << endl;
	}*/
	for (int i = 0; i < n; i++) {
		if (isStatic[i] && !isStatic[md(i + 1)]) {
			if (nxt[i] == -1) continue;
			//cout << i << endl;
			int f1 = i;
			int f2 = nxt[i];
			if (f2 < f1) f2 += n;
			int l = f2 - f1;
			if ((l - 1) >= 2 * k) {
				col.push_back({ {md(i + 1), md(i + k)}, ans[i] });
				col.push_back({ {md(f2 - md(k)), md(f2 - 1)}, ans[md(f2)] });
			}
			else {
				if (l % 2 == 0) {
					int m = (f1 + f2) / 2;
					isStatic[md(m)] = true;
					if (ans[f1] == ans[md(f2)]) ans[md(m)] = ans[f1];
					if (md(md(m) - md(i)) == 1) continue;
					col.push_back({ {md(i + 1), md(m - 1)}, ans[i] });
					col.push_back({ {md(m + 1), md(f2 - 1)}, ans[md(f2)] });
				}
				else {
					//cout << f1 << " " << f2 << endl;
					int m = (f1 + f2) / 2;
					//cout << m << " CRINGE\n";
					col.push_back({ {md(i + 1), md(m)}, ans[i] });
					col.push_back({ {md(m + 1), md(f2 - 1)}, ans[md(f2)] });
				}
			}
		}
	}
	sort(all(col));
	int tmp = 0;
	//for (auto u : col) cout << u.first.first << " " << u.first.second << " " << u.second << endl;
	int cnt = 0;
	for (int i = 0; ; i = md(i + 1)) {
		//assert(cnt < 3 * n);
		if (tmp == col.size()) break;
		assert(md(col[tmp].first.first) == col[tmp].first.first);
		assert(md(col[tmp].first.second) == col[tmp].first.second);
		if (col.size() > 1 && (tmp < (col.size() - 1))) {
			//	assert(!bet(col[tmp + 1].first.first, col[tmp].first.second, col[tmp + 1].first.second));
		}
		cnt++;
		if (bet(col[tmp].first.first, i, col[tmp].first.second)) {
			ans[i] = col[tmp].second;
			isStatic[i] = true;
		}
		if (i == col[tmp].first.second) tmp++;
	}
	for (int i = 0; i < n; i++) {
		if (isStatic[i]) {
			pr(ans[i]);
			continue;
		}
		if (k % 2) ans[i] ^= 1;
		pr(ans[i]);
	}
}