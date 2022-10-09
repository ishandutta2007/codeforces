#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll l[100005], r[100005], sol;

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	sort(l, l + n);
	sort(r, r + n);
	for (int i = 0; i < n; i++) {
		sol += max(l[i], r[i]);
	}
	cout << sol + n;
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}