#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

const int maxN = 523456;

vector<int> v;

set<i64> cfish;
multiset<i64> fish;

int n, w[maxN], id[maxN], cnt, op[maxN];
i64 c[maxN];
char s[10];

void add(int x, int s) {
	for (; x <= n; x += x & -x)
		c[x] += s;
}

i64 query(int x) {
	i64 s = 0;
	for (; x; x -= x & -x) {
		s += c[x];
	}
	return s;
}

int countpairs() {
	int ans = 0;
	for (auto w : cfish) {
		if (w == 1ll << 60) continue;
		int id = lower_bound(v.begin(), v.end(), w) - v.begin() + 1;
		i64 lesw = query(id - 1);
		if (2 * lesw < w) {
			ans++;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s%d", s, &w[i]);
		v.push_back(w[i]);
		if (s[0] == '+') op[i] = 1;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		id[i] = lower_bound(v.begin(), v.end(), w[i]) - v.begin() + 1;
	}
	fish.insert(0);
	fish.insert(1ll << 60);
	cfish.insert(1ll << 60);
	for (int i = 0; i < n; i++) {
		if (op[i]) {
			cnt++;
			add(id[i], w[i]);
			auto nex = fish.lower_bound(w[i]);
			auto pre = nex;
			--pre;
			if (*nex > 2 * (*pre)) {
				cfish.erase(*nex);
			}
			if (*nex > 2 * w[i]) {
				cfish.insert(*nex);
			}
			if (w[i] > 2 * (*pre)) {
				cfish.insert(w[i]);
			}
			fish.insert(w[i]);
		} else {
			cnt--;
			add(id[i], -w[i]);
			auto nex = fish.lower_bound(w[i]);
			auto pre = nex;
			--pre;
			++nex;
			if (*nex > 2 * w[i]) {
				cfish.erase(*nex);
			}
			if (w[i] > 2 * (*pre)) {
				cfish.erase(w[i]);
			}
			if (*nex > 2 * (*pre)) {
				cfish.insert(*nex);
			}
			fish.erase(fish.lower_bound(w[i]));
		}
		printf("%d\n", cnt - countpairs());
	}
}