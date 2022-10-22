#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using u64 = unsigned long long;
const int mxn = 2005;
const int blk = 64, mxb = mxn / blk + 5;

int n, m, q;
u64 mask[mxn][mxb];

std::set <std::pair <int, int> > st;

int count(int a) {
	int ans = 0;
	rep(i, (m - 1) / blk + 1) ans += __builtin_popcountll(mask[a][i]);
	return ans;
}

bool check(int a, int b) {
	bool ok1 = false, ok2 = false;
	rep(i, (m - 1) / blk + 1) {
		ok1 |= ~mask[a][i] & mask[b][i];
		ok2 |= ~mask[b][i] & mask[a][i];
	}
	return ok1 && ok2;
}

std::set <std::pair <int, int> > z;

void modify(int a, int b, int type) {
	if (check(a, b)) {
		if (type == +1) z.insert({a, b});
		else z.erase({a, b});
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	rep(i, n) st.insert({0, i});
	while (q --) {
		int a, l, r;
		scanf("%d %d %d", &a, &l, &r);
		-- a, -- l;
		auto it = st.lower_bound(std::make_pair(count(a), a));
		if (it != st.begin()) modify(std::prev(it)->second, it->second, -1);
		if (std::next(it) != st.end()) modify(it->second, std::next(it)->second, -1);
		if (it != st.begin() && std::next(it) != st.end()) modify(std::prev(it)->second, std::next(it)->second, +1);
		st.erase({count(a), a});
		for (; l % blk && l < r; ++ l) mask[a][l / blk] ^= u64(1) << (l % blk);
		for (; l + blk <= r; l += blk) mask[a][l / blk] ^= u64(-1);
		for (; l < r; ++ l) mask[a][l / blk] ^= u64(1) << (l % blk);
		st.insert({count(a), a});
		it = st.lower_bound(std::make_pair(count(a), a));
		if (it != st.begin() && std::next(it) != st.end()) modify(std::prev(it)->second, std::next(it)->second, -1);
		if (it != st.begin()) modify(std::prev(it)->second, it->second, +1);
		if (std::next(it) != st.end()) modify(it->second, std::next(it)->second, +1);
		if (z.empty()) puts("-1");
		else {
			int x0 = z.begin()->first;
			int x1 = z.begin()->second;
			int y0 = -1, y1 = -1;
			rep(i, (m - 1) / blk + 1) {
				if (~mask[x0][i] & mask[x1][i]) y0 = i * blk + __builtin_ctzll(~mask[x0][i] & mask[x1][i]);
				if (~mask[x1][i] & mask[x0][i]) y1 = i * blk + __builtin_ctzll(~mask[x1][i] & mask[x0][i]);
			}
			if (x0 > x1) std::swap(x0, x1);
			if (y0 > y1) std::swap(y0, y1);
			printf("%d %d %d %d\n", x0 + 1, y0 + 1, x1 + 1, y1 + 1);
		}
	}
	return 0;
}