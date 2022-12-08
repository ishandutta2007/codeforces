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

const ll inf0 = 2 * 1024 * 1024 * 1023;
const ll inf = inf0 * inf0;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll n, m, k;
	cin >> n >> m >> k;
	vector < ll > p(m);
	for (int i = 0; i < m; i++) {
		cin >> p[i];
		p[i]--;
	}
	ll cur = 0;
	ll cnt = 0;
	ll g = 0;
	while (cur != m) {
		cnt++;
		ll t = (p[cur] - g) / k;
		ll f = (t + 1) * k;
		ll h = lower_bound(p.begin(), p.end(), f + g) - p.begin();
		//cout << h << " " << f << endl;
		g += (h - cur);
		cur = h;
	}
	cout << cnt << endl;
	return 0;
}