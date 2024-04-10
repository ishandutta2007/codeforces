#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

int n, m, q;
int fen[2501][2501];
int idt[2501][2501];
int query(int i, int j) {
	int t;
	int ret = 0ll;
	while (i) {
		t = j;
		while (t) {
			ret ^= fen[i][t];
			t -= (t & -t);
		}
		i -= (i & -i);
	}
	return ret;
}

void update(int i, int j, int x) {
	int t;
	while (i <= n) {
		t = j;
		while (t <= m) {
			fen[i][t] ^= x;
			t += (t & -t);
		}
		i += (i & -i);
	}
}

struct rect {
	int x1, y1, x2, y2;
	int val;
	bool operator<(const rect &p) const {
		if (x1 == p.x1) {
			if (y1 == p.y1) {
				if (x2 == p.x2) {
					return y2 < p.y2;
				}
				return x2 < p.x2;
			}
			return y1 < p.y1;
		}
		return x1 < p.x1;
	}
};

int rl() {
	int ret = 0ll;
	ret ^= rand();
	ret <<= 15;
	ret ^= rand();
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
	srand(time(NULL));
	int t, x1, y1, x2, y2;
	for (int i = 0; i < q; ++i) {
		cin >> t >> x1 >> y1 >> x2 >> y2;
		rect r = { x1, y1, x2, y2, 0ll };
		if (t == 1) {
			idt[x1][y1] = r.val = rl();
			update(x1, y1, r.val);
			update(x1, y2 + 1, r.val);
			update(x2 + 1, y1, r.val);
			update(x2 + 1, y2 + 1, r.val);
		}
		else if (t == 2) {
			r.val = idt[x1][y1];
			update(x1, y1, r.val);
			update(x1, y2 + 1, r.val);
			update(x2 + 1, y1, r.val);
			update(x2 + 1, y2 + 1, r.val);
		}
		else {
			if (query(x1, y1) == query(x2, y2)) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}