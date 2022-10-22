#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define tab "\t"
#define endl "\n"

#define ferr std::cerr

#ifdef DEBUG
std::ifstream fin("in");
std::ofstream fout("out");
#else
#define fin std::cin
#define fout std::cout
#endif

const int mxn = 1 << 18;

int n, q;
char s[mxn];

struct item {
	int s0, s1;
	int cl, cr;
	item(): s0(0), s1(0), cl(-1), cr(-1) {}
	item(int c): s0(0), s1(0), cl(c), cr(c) {}
	friend item operator + (const item &i, const item &j) {
		if (!~i.cl) return j;
		if (!~j.cl) return i;
		item k;
		k.s0 = i.s0 + j.s0 + (i.cr == 0 && j.cl == 0);
		k.s1 = i.s1 + j.s1 + (i.cr == 1 && j.cl == 1);
		k.cl = i.cl, k.cr = j.cr;
		return k;
	}
};

item t[mxn << 1];

inline item query(int l, int r) {
	item iL, iR;
	for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
		if (l & 1) iL = iL + t[l ++];
		if (r & 1) iR = t[-- r] + iR;
	}
	return iL + iR;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	fin >> n >> q;
	fin >> s;
	rep(i, n) t[i + mxn] = item(s[i] - '0');
	for (int i = mxn - 1; i; -- i) t[i] = t[i << 1] + t[i << 1 | 1];
	while (q --) {
		int l, r;
		fin >> l >> r;
		-- l, -- r;
		item i = query(l, r + 1);
		fout << 1 + i.s0 + i.s1 - std::min(i.s0, i.s1) << endl;
	}
	return 0;
}