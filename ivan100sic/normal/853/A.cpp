#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, k;
pair<int, int> a[300005];
int sol[300005];
set<int> moze;

long long tot;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	for (int i=1; i<=n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}

	for (int i=k+1; i<=k+n; i++) {
		moze.insert(i);
	}

	sort(a+1, a+n+1);

	for (int i=n; i>=1; i--) {
		int u = *moze.lower_bound(a[i].second);
		moze.erase(u);
		tot += a[i].first * 1ll * (u - a[i].second);
		sol[a[i].second] = u;
	}

	cout << tot << '\n';
	for (int i=1; i<=n; i++) {
		cout << sol[i] << ' ';
	}

}