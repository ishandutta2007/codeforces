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
#include <queue>
#include <complex>

#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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


void solve() {
	int n; cin >> n;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt += a[i];
	}
	if (cnt == 1) {
		cout << -1 << endl;
		return;
	}
	int p = cnt;
	int ans = 4e18;
	vector<int> id;
	for (int i = 0; i < n; i++) {
		if (a[i]) id.push_back(i);
	}
	//cout << cnt << endl;
	vector<int> pref(cnt); pref[0] = id[0];
	vector<int> suff(cnt); suff[cnt - 1] = id[cnt - 1];
	for (int i = 1; i < cnt; i++) pref[i] = pref[i - 1] + id[i];
	for (int i = cnt - 2; i >= 0; i--) suff[i] = suff[i + 1] + id[i];
	/*for (int i = 0; i < cnt; i++) {
		cout << i + 1 << " " << pref[i] << " " << suff[i] << endl;
	}*/
	/*cout << p << endl;
	for (int i : id) cout << i << " ";
	cout << endl;*/
	p = cnt;
	int f = 0;
	for (long long i = 0; i < cnt; i += p) {
		int mini = 4e18;
		for (long long j = i; j < (i + p); j++) {
			//cout << i << " JOPA " << j << endl;
			//cout << id[j] << " " << (j - i + 1) * a[id[j]] << endl;
			int left = (j - i + 1) * id[j] - pref[j] + (i ? pref[i - 1] : 0);
			int right = (suff[j] - (i + p - j) * id[j] - (i + p != cnt ? suff[i + p] : 0));
			//cout << left << " " << right << endl;
			mini = min(left + right, mini);
		}
		f += mini;
	}
	ans = min(ans, f);
	for (int i = 2; i <= sqrt(cnt); i++) {
		if (cnt % i == 0) {
			p = i;
			f = 0;
			for (long long i = 0; i < cnt; i += p) {
				int mini = 4e18;
				for (long long j = i; j < (i + p); j++) {
					//cout << i << " JOPA " << j << endl;
					//cout << id[j] << " " << (j - i + 1) * a[id[j]] << endl;
					int left = (j - i + 1) * id[j] - pref[j] + (i ? pref[i - 1] : 0);
					int right = (suff[j] - (i + p - j) * id[j] - (i + p != cnt ? suff[i + p] : 0));
					//cout << left << " " << right << endl;
					mini = min(left + right, mini);
				}
				f += mini;
			}
			ans = min(ans, f);
			f = 0;
			p = cnt / i;
			for (long long i = 0; i < cnt; i += p) {
				int mini = 4e18;
				for (long long j = i; j < (i + p); j++) {
					//cout << i << " JOPA " << j << endl;
					//cout << id[j] << " " << (j - i + 1) * a[id[j]] << endl;
					int left = (j - i + 1) * id[j] - pref[j] + (i ? pref[i - 1] : 0);
					int right = (suff[j] - (i + p - j) * id[j] - (i + p != cnt ? suff[i + p] : 0));
					//cout << left << " " << right << endl;
					mini = min(left + right, mini);
				}
				f += mini;
			}
			ans = min(ans, f);
		}
	}
	
	cout << ans << endl;
}