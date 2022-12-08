#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 998244353;

ll cnt(int l1, int r1, int l2, int r2) {
	if (r1 < l2 || r2 < l1) return 0;
	if (l2 <= l1 && r1 <= r2) return r1 - l1 + 1;
	if (l1 <= l2 && r2 <= r1) return r2 - l2 + 1;
	if (l1 <= l2) return r1 - l2 + 1;
	return r2 - l1 + 1;
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int lf = 0, rl = 0;
	int l, r;
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		ans += cnt(lf, l, rl, r);
		if (lf == rl) ans--;
		lf = l;
		rl = r;
	}
	cout << ans << endl;
	//system("pause");
	return 0;
}