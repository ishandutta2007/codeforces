#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;
typedef long long llong;

int n;
int a[100];
map<int, int> prime;

map<int, int> grundy;
int getGrundy(int x) {
	set<int> used;
	auto it = grundy.find(x);
	if (it != grundy.end()) return it->second;
	for (int i = 1; i < 31; ++i) {
		int j = (x >> i) | (x & ((1 << (i - 1)) - 1));
		if (x == j) continue;
		used.insert(getGrundy(j));
	}
	int i;
	for (i = 0; used.find(i) != used.end(); ++i);
	grundy[x] = i;
	return i;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		for (int j = 2; j * j <= a[i]; ++j) {
			if (a[i] % j > 0) continue;
			int cnt = 0; a[i] /= j;
			while (a[i] % j == 0) {
				a[i] /= j;
				++cnt;
			}
			prime[j] |= (1 << cnt);
		}
		if (a[i] > 1) prime[a[i]] |= 1;
	}
	int ans = 0;
	grundy.insert({ 0, 0 });
	auto i = prime.lower_bound(0);
	while (i != prime.end()) {
		ans ^= getGrundy(i->second);
		++i;
	}
	printf(ans ? "Mojtaba\n" : "Arpa\n");
	return 0;
}