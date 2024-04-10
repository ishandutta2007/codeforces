#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int n;
int a[200005];
map<int, int> last;
int d[200005], p[200005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	int best_val = -1;
	int best_pos = -1;

	fill(p, p + 200005, -1);

	for (int i = 1; i <= n; i++) {
		if (last.count(a[i] - 1)) {
			p[i] = last[a[i] - 1];
			d[i] = d[p[i]] + 1;
		}
		if (d[i] > best_val) {
			best_val = d[i];
			best_pos = i;
		}
		last[a[i]] = i;
	}

	int x = best_pos;
	vector<int> sol;
	while (x != -1) {
		sol.push_back(x);
		x = p[x];
	}

	reverse(sol.begin(), sol.end());

	cout << sol.size() << '\n';
	for (int x : sol) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}