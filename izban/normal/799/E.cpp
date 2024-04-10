#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;

struct MySet {
	multiset<int> st;
	ll sum;

	MySet() {
		sum = 0;
	}

	void add(int x) {
		sum += x;
		st.insert(x);
	}

	void del(int x) {
		auto it = st.find(x);
		assert(it != st.end());
		st.erase(it);
		sum -= x;
	}

	bool empty() {
		return st.empty();
	}

	int mx() {
		assert(!st.empty());
		return *st.rbegin();
	}

	int mn() {
		assert(!st.empty());
		return *st.begin();
	}

	int size() {
		return st.size();
	}

	ll getSum() {
		return sum;
	}
};

struct MyHeap {
	// st1 contains ~k minimums, where k is last query
	// queryes are decreasing
	MySet st1, st2;

	MyHeap() {
		st1 = MySet();
		st2 = MySet();
	}

	void add(int x) {
		if (st1.empty() || st1.mx() <= x) {
			st2.add(x);
		}
		else {
			st1.add(x);
		}
	}

	ll get(int k) {
		while (st1.size() > k) {
			int x = st1.mx();
			st1.del(x);
			st2.add(x);
		}
		while (st1.size() < k) {
			int x = st2.mn();
			st2.del(x);
			st1.add(x);
		}
		return st1.getSum();
	}

	int size() {
		return st1.size() + st2.size();
	}
};

const ll INF = 1e18;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	
	int n, m, k;
	while (scanf("%d%d%d", &n, &m, &k) == 3) {
		vector<int> c(n);
		for (int i = 0; i < n; i++) scanf("%d", &c[i]);

		vector<int> mask(n);
		for (int i = 0; i < 2; i++) {
			int w;
			scanf("%d", &w);
			for (int j = 0; j < w; j++) {
				int x;
				scanf("%d", &x);
				x--;
				mask[x] |= 1 << i;
			}
		}

		vector<vector<int> > a(4);
		for (int i = 0; i < n; i++) a[mask[i]].push_back(c[i]);
		for (int i = 0; i < 4; i++) {
			sort(a[i].begin(), a[i].end());
		}

		vector<vector<ll> > s(4);
		for (int i = 0; i < 4; i++) {
			s[i].resize(a[i].size() + 1);
			for (int j = 0; j < (int)a[i].size(); j++) {
				s[i][j + 1] = s[i][j] + a[i][j];
			}
		}

		MyHeap h = MyHeap();
		for (int i = 0; i < (int)a[0].size(); i++) h.add(a[0][i]);
		for (int i = 1; i <= 2; i++) {
			for (int j = k; j < (int)a[i].size(); j++) {
				h.add(a[i][j]);
			}
		}

		ll ans = INF;
		for (int common = 0; common <= min((int)a[3].size(), m); common++) {
			int t = max(k - common, 0);

			if (t <= (int)a[1].size() && t <= (int)a[2].size()) {
				ll cur = s[3][common];
				cur += s[1][t];
				cur += s[2][t];
				if (common + t + t <= m && h.size() >= m - common - t - t) {
					ans = min(ans, cur + h.get(m - common - t - t));
				}
			}
			if (t > 0) {
				if (t <= (int)a[1].size()) h.add(a[1][t - 1]);
				if (t <= (int)a[2].size()) h.add(a[2][t - 1]);
			}
		}
		if (ans == INF) ans = -1;
		cout << ans << endl;
	}

	return 0;
}