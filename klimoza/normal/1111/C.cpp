#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")												
#pragma GCC optimize("rename-registers")									
#pragma GCC optimize("move-loop-invariants")								
#pragma GCC optimize("unswitch-loops")											
#pragma GCC optimize("function-sections")										
#pragma GCC optimize("data-sections")										
#pragma GCC optimize("branch-target-load-optimize")							
#pragma GCC optimize("branch-target-load-optimize2") 						
#pragma GCC optimize("btr-bb-exclusive")
#pragma comment(linker, "/stack:200000000")


#include <iostream>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 998244353;
double eps = 1e-7;

vector<pair<ll, int>> m;
int n, k;
ll a, b;

pair<ll, int> ans(int l, int r) {
	int f1, f2;
	f1 = -1;
	f2 = m.size() - 1;
	while (f2 - f1 > 1) {
		int mid = (f2 + f1) / 2;
		if (m[mid].first < l) f1 = mid;
		else f2 = mid;
	}
	int lb = f2;
	f1 = 0;
	f2 = m.size();
	while (f2 - f1 > 1) {
		int mid = (f2 + f1) / 2;
		if (m[mid].first <= r) f1 = mid;
		else f2 = mid;
	}
	int rb = f1;
	//cout << lb << " " << rb << " " << l << " " << r << endl;
	if (m[lb].first > r || m[rb].first < l) return { a, 0 };
	else {
		if (r == l) return { b * m[lb].second, m[lb].second };
		auto k1 = ans(l, (l + r) / 2);
		auto k2 = ans(((l + r) / 2) + 1, r);
		//cout << k1.first << " " << k1.second << " " << k2.first << " " << k2.second << " " << l << " " << r << endl;
		if (!k1.second) {
			return { min(k2.first + a, b * k2.second * (r - l + 1)), k2.second };
		}
		if (!k2.second) {
			return { min(k1.first + a, b * k1.second * (r - l + 1)), k1.second };
		}
		return { k1.first + k2.first, k1.second + k2.second };
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> k >> a >> b;
	vector<int> h(k);
	for (int i = 0; i < k; i++) {
		cin >> h[i]; h[i]--;
	}
	sort(h.begin(), h.end());
	int cnt = 1;
	for (int i = 1; i < k; i++) {
		if (h[i] == h[i - 1]) cnt++;
		else {
			m.push_back({ h[i - 1], cnt });
			cnt = 1;
		}
	}
	m.push_back({ h[k - 1], cnt });
	cout << ans(0, (1 << n) - 1).first << endl;
	//system("pause");
	return 0;
}