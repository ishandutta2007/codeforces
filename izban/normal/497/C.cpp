#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = 1 << 17;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

struct Song {
	int l, r, p;

	void read(int i) {
		scanf("%d%d", &l, &r);
		p = i;
	}

	bool operator< (const Song &s) const {
		return l < s.l || l == s.l && r < s.r;
	}
};

struct Man {
	int l, r, k, p;

	void read(int i) {
		scanf("%d%d%d", &l, &r, &k);
		p = i;
	}

	bool operator< (const Man &m) const {
		return l < m.l || l == m.l && r < m.r;
	}
};

int n, m;
Song a[maxn];
Man b[maxn];
vector<pair<int, int> > c;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
	while (scanf("%d", &n) == 1) {
		for (int i = 0; i < n; i++) {
			a[i].read(i);
		}
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			b[i].read(i);
		}
		sort(a, a + n);
		sort(b, b + m);

		vector<int> ans(n, -1);
		set<pair<int, int> > st;
		int j = 0;
		bool ok = 1;
		for (int i = 0; i < n; i++) {
			while (j < m && b[j].l <= a[i].l) {
				st.insert(make_pair(b[j].r, j));
				j++;
			}
			set<pair<int, int> > :: iterator it = st.lower_bound(make_pair(a[i].r, -1));
			if (it == st.end()) {
				ok = 0;
				continue;
			}
			int v = it->second;
			ans[a[i].p] = b[v].p;
			b[v].k--;
			if (b[v].k == 0) st.erase(it);
		}
		if (ok) {
			cout << "YES" << endl;
			for (int i = 0; i < n; i++) cout << ans[i] + 1 << " \n"[i + 1 == n];
		} else {
			cout << "NO" << endl;
		}
	}

    return 0;
}