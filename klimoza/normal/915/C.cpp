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
ll mod = 1e9 + 7;

bool lss(vector<int> a1, vector<int> a2) {
	for (int i = 0; i < a1.size(); i++) {
		if (a1[i] < a2[i]) return true;
		if (a1[i] > a2[i]) return false;
	}
	return true;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	ll a, b;
	cin >> a >> b;
	int n = 0, m = 0;
	ll a1 = a, b1 = b;
	while (a1) {
		n++; a1 /= 10;
	}
	vector<int> bf;
	while (b1) {
		bf.push_back(b1 % 10);
		m++; b1 /= 10;
	}
	reverse(bf.begin(), bf.end());
	vector<int> ans(m);
	vector<int> deg;
	for (int i = m - 1; i >= 0; i--) {
		if (!a) break;
		ans[i] = a % 10;
		deg.push_back(a % 10);
		a /= 10;
	}
	sort(deg.begin(), deg.end());
	for (int i = m - n; i < m; i++) {
		for (int j = deg.size() - 1; j >= 0; j--) {
			ans[i] = deg[j];
			int t = i + 1;
			for (int k = 0; k < deg.size(); k++) {
				if (k == j) continue;
				ans[t++] = deg[k];
			}
			if (lss(ans, bf)) {
				swap(deg[j], deg[deg.size() - 1]);
				deg.pop_back();
				sort(deg.begin(), deg.end());
				break;
			}
		}
	}
	for (int i = m - n; i < m; i++) {
		cout << ans[i];
	}
	cout << endl;
	//system("pause");
	return 0;
}