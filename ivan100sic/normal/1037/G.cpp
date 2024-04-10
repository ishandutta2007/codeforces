#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void set(int pos, const T& val) {
		while (pos < size) {
			a[pos] ^= val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret ^= a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}

	int get(int l, int r) {
		return sum(r) ^ sum(l-1);
	}
};

fenwick<uint8_t, 100005> drvo[27];

int n;
string s;

int levi_pos[100005][27], desni_pos[100005][27];
int pos[27][100005], sz[27];

int t[27];

int mex(int mask) {
	return __builtin_ctz(~mask);
}

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
gp_hash_table<ull, int> ans_cache;
// unordered_map<ll, int> ans_cache;
*/

struct hash_node {
	ull hash;
	int val;
};

struct my_hash_table {
	hash_node a[16777216 / 2 + 10000];

	void set(ull hash, int val) {
		int pos = hash & 0x7fffff;
		while (a[pos].hash) pos++;
		a[pos].hash = hash;
		a[pos].val = val;
	}

	int get(ull hash) {
		int pos = hash & 0x7fffff;
		while (a[pos].hash && a[pos].hash != hash) pos++;
		if (a[pos].hash == 0)
			return -1;
		return a[pos].val;
	}
} ans_cache;

set<int> unsolved[27];

int resi(int l, int r) {
	ull hash = (l * 44312566316561ull + r * 23982987381143481ull);
	// resen?
	{
		auto it = ans_cache.get(hash);
		if (it != -1)
			return it;
	}

	// cerr << "solving " << l << ' ' << r << '\n';
	// svako slovo gledam da skinem
	int mex_mask = 0;

	for (int x=0; x<26; x++) {
		int xl = desni_pos[l][x];
		int xr = levi_pos [r][x];

		if (xl > xr)
			continue;

		int unutra_val = 0;

		// cerr << l << ' ' << r << ' ' << x << ' ' << xl << ' ' << xr << '\n';

		while (xl < xr) {
			auto it = unsolved[x].lower_bound(xl+1);

			if (it != unsolved[x].end() && *it <= xr) {
				int ql = *it;
				int qr = desni_pos[ql][x] - 1;
				int ans;
				if (ql <= qr) {
					ans = resi(ql, qr);
				} else {
					ans = 0;
				}
				drvo[x].set(ql, ans);
				unsolved[x].erase(it);
			} else {
				unutra_val ^= drvo[x].get(xl+1, xr);
				break;
			}
		}

		// levi ostatak?
		if (xl > l)
			unutra_val ^= resi(l, xl-1);

		if (xr < r)
			unutra_val ^= resi(xr+1, r);

		// cerr << "letter " << x << " value " << (int)unutra_val << '\n';

		mex_mask |= 1 << (int)unutra_val;
	}

	int mmm = mex(mex_mask);
	ans_cache.set(hash, mmm);
	// cerr << "solved " << l << ' ' << r << ' ' << mmm << '\n';

	return mmm;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	n = s.size();
	s = string("{") + s + string("{"); // z+1

	// preprocess
	fill(t, t+27, -123123123);
	for (int i=0; i<=n+1; i++) {
		t[s[i]-'a'] = i;
		copy(t, t+27, levi_pos[i]);
	}

	fill(t, t+27, 123123123);
	for (int i=n+1; i>=0; i--) {
		t[s[i]-'a'] = i;
		copy(t, t+27, desni_pos[i]);
	}

	for (int i=1; i<=n; i++) {
		int x = s[i] - 'a';
		pos[x][sz[x]++] = i;
	}

	for (int x=0; x<26; x++) {
		for (int i=0; i<sz[x]-1; i++) {
			int xl = pos[x][i] + 1;
			unsolved[x].insert(xl);
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << (resi(l, r) ? "Alice\n" : "Bob\n");
		// cerr << "~~~\n";
		// cout << s.substr(l, r-l+1) << '\n';
	}
}