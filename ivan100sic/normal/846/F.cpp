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

int n;
int a[1000005];
vector<int> b[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[a[i]].push_back(i);
	}

	// za svaki broj racunam njegov contrib
	long long tot = 0;

	auto kv = [](long long x) { return x * x; };

	for (int i=1; i<=1'000'000; i++) {
		long long dod = n * 1ll * n;
		int prev = 0;
		for (int x : b[i]) {
			dod -= kv(x - prev - 1);
			prev = x;
		}
		dod -= kv(n - prev);

		tot += dod;
	}

	cout.precision(20);
	cout << fixed << tot * 1.0 / n / n;
}