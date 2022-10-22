/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

namespace suffix_array {
	constexpr int N = 2e5 + 5;
	int cnt[N];

	vector<int> build(string s) {
		const int M = 1 << 8;

		s += "#";
		int n = s.size(), sz = M;

		vector<int> p(n), c(n), pn(n), cn(n);

		fill(cnt, cnt + sz, 0);
		for (int i = 0; i < n; i++) cnt[s[i]] ++;
		for (int i = 1; i < sz; i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1; ~i; i--) p[-- cnt[s[i]] ] = i;

#define get_c(i) (s[p[i]])
		c[p[0]] = (sz = 1) - 1;
		for (int i = 1; i < n; i++) {
			sz += get_c(i) != get_c(i - 1);
			c[p[i]] = sz - 1;
		}
#undef get_c

		for (int h = 1; h < n; h <<= 1) {
			swap(c, cn);
			for (int i = 0; i < n; i++)
				pn[i] = p[i] - h < 0 ? p[i] - h + n : p[i] - h;

			fill(cnt, cnt + sz, 0);
			for (int i = 0; i < n; i++) cnt[cn[pn[i]]] ++;
			for (int i = 1; i < sz; i++) cnt[i] += cnt[i - 1];
			for (int i = n - 1; ~i; i--) p[-- cnt[cn[pn[i]]] ] = pn[i];

#define get_c(i) pair<int, int> (cn[p[i]], cn[(p[i] + h) % n])
			c[p[0]] = (sz = 1) - 1;
			for (int i = 1; i < n; i++) {
				sz += get_c(i) != get_c(i - 1);
				c[p[i]] = sz - 1;
			}
#undef get_c
		}
		return p;
	}

	vector<int> lcp_build(const string &s, const vector<int> &p) {
		int n = s.size();
		vector<int> pos(n + 1), lcp(n);

		for (int i = 0; i <= n; i++)
			pos[p[i]] = i;

		for (int i = 0, k = 0; i < n; i++) {
			int j = p[pos[i] - 1];
			while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
			lcp[pos[i] - 1] = k;
			k = max(k - 1, 0);
		}
		return lcp;
	}
}

const int N = 2e5 + 5;

int n, par[N], cnt[N], pos[N], mx;
long long res;

string s, t;
vector<int> p, lcp, act[N];

inline int find(int u) {
	return par[u] == u ? u : par[u] = find(par[u]);
}

inline void merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return ;
	par[u] = v;
	cnt[v] += cnt[u];
	mx = max(mx, cnt[v]);
}

void Hollwo_Pelw() {
	cin >> n >> s >> t;
	reverse(s.begin(), s.end());
	reverse(t.begin(), t.end());

	p = suffix_array::build(s);
	lcp = suffix_array::lcp_build(s, p);

	for (int i = 1; i <= n; i++)
		pos[n - p[i]] = i;
	for (int i = 1; i < n; i++)
		act[lcp[i]].push_back(i);

	iota(par + 1, par + n + 1, 1);
	for (int i = 1; i <= n; i++)
		cnt[i] = t[p[i]] == '1' ? 0 : 1;

	for (int i = n; i >= 1; i--) {
		if (t[n - i] == '0')
			mx = max(mx, 1);

		for (auto j : act[i])
			merge(j, j + 1);
		res = max(res, 1ll * mx * i);
	}

	cout << res;
}