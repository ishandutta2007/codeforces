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

const int N = (1 << 20) + 7;

int mask[N];

void solve() {
	fill(mask, mask + N, 0);
	string st;
	cin >> st;
	int n = st.size();
	for (int i = 0; i < n; i++) {
		int newmask = 0;
		for (int j = i; j < min(n, i + 20); j++) {
			if (newmask & (1 << (st[j] - 'a'))) break;
			newmask |= (1 << (st[j] - 'a'));
			mask[newmask] = (j - i + 1);
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << 20); i++) {
		for (int j = 0; j < 20; j++) {
			if (i & (1 << j)) {
				mask[i] = max(mask[i], mask[i ^ (1 << j)]);
			}
		}
		ans = max(ans, mask[i] + mask[((1 << 20) - 1) ^ i]);
	}
	cout << ans << endl;
}