#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[100005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	list<ll> b;
	for (int i = 59; i >= 0; i--) {
		vector<ll> c;
		for (int j = 0; j < n; j++) {
			if (a[j] & (1ll << i)) {
				c.push_back(a[j]);
				a[j] = 0;
			}
		}
		vector<list<ll>::iterator> pos;
		pos.push_back(b.begin());
		for (auto it = b.begin(); it != b.end(); ++it) {
			if (*it & (1ll << i)) {
				pos.push_back(next(it));
			}
		}
		if (c.size() > pos.size()) {
			cout << "No\n";
			return;
		}
		
		for (int i = 0; i < (int)c.size(); i++) {
			b.insert(pos[i], c[i]);
		}
	}

	cout << "Yes\n";
	for (ll x : b) {
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