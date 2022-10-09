#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>
	ordered_set;
// find_by_order(size_t) -> iterator, order_of_key(val) -> size_t

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		pos++;
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		pos++;
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<int, 100055> drvo;

int kmp_count(const string& s, const string& p) {
	int m = p.size();
	vector<int> f(m+1);
	f[0] = -1;
	for (int i=1; i<=m; i++) {
		int r = f[i-1];
		while (r != -1 && p[r] != p[i-1])
			r = f[r];
		f[i] = r + 1;
	}

	static int trans[100005][26];

	for (int j=0; j<26; j++)
		trans[0][j] = p[0]-'a' == j;

	for (int i=1; i<m; i++) {
		for (int j=0; j<26; j++) {
			trans[i][j] = p[i]-'a' == j ? i + 1 : trans[f[i]][j];
		}
	}

	int r = 0, z = 0;
	for (char c : s) {
		r = trans[r][c-'a'];
		if (r == m) {
			z++;
			r = f[r];
		}
	}

	return z;
}

int n, q;
string s0;
string qs[100005];
int ql[100005], qr[100005], qa[100005];
const int B = 7;
basic_string<int> se[B+1];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s0;
	n = s0.size();
	cin >> q;
	for (int i=0; i<q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			char c;
			cin >> x >> c;
			qs[i] = string(1, c);
			ql[i] = -1;
			qr[i] = x-1;
		} else {
			cin >> ql[i] >> qr[i] >> qs[i];
			ql[i]--;
			qr[i]--;
		}
	}

	// resi dugacke
	{
		string s = s0;
		for (int i=0; i<q; i++) {
			if (ql[i] == -1) {
				s[qr[i]] = qs[i][0];
			} else if ((int)qs[i].size() > B) {
				qa[i] = kmp_count(s.substr(ql[i], qr[i]-ql[i]+1), qs[i]);
			} else {
				// uvrsti ovo u kratke
				se[qs[i].size()] += i;
			}
		}
	}

	// kratki
	for (int l=1; l<=B; l++) {
		// prikupi heseve
		gp_hash_table<ull, int> ht;
		int cnt = 0;
		ull mask = (1ull << (5*l)) - 1;
		vector<vector<tuple<int, int, int>>> deltas(se[l].size() + 2);
		for (int i : se[l]) {
			ull h = 0;
			for (char c : qs[i])
				h = ((h << 5) | (c & 31)) & mask;
			int& ref = ht[h];
			if (ref == 0)
				ref = ++cnt;
			deltas[ref].emplace_back(i, 0, 0);
		}
		string s = s0;

		auto dadd = [&](ull h, int t, int p, int v) {
			auto it = ht.find(h);
			if (it == ht.end())
				return;
			int i = it->second;
			deltas[i].emplace_back(t, p, v);
		};
		// procesiraj izmene na stringu 
		// prvo da pocnemo od osnova
		{
			ull h = 0;
			for (int j=0; j<n; j++) {
				h = ((h << 5) | (s[j] & 31)) & mask;
				if (j+1 >= l)
					dadd(h, -1, j, +1);
			}
		}
		// zatim odradimo sve izmene
		for (int i=0; i<q; i++) {
			if (ql[i] == -1) {
				int p = qr[i];
				char cnew = qs[i][0];
				int jl = max(0, p-l+1);
				int jh = min(n-1, p+l-1);
				ull h = 0;
				for (int j=jl; j<=jh; j++) {
					h = ((h << 5) | (s[j] & 31)) & mask;
					if (j-jl+1 >= l)
						dadd(h, i, j, -1);
				}
				s[p] = cnew;
				h = 0;
				for (int j=jl; j<=jh; j++) {
					h = ((h << 5) | (s[j] & 31)) & mask;
					if (j-jl+1 >= l)
						dadd(h, i, j, +1);
				}
			}
		}
		// odjavimo se bc ynot
		{
			ull h = 0;
			for (int j=0; j<n; j++) {
				h = ((h << 5) | (s[j] & 31)) & mask;
				if (j+1 >= l)
					dadd(h, 123123123, j, -1);
			}
		}

		// zatim pokidamo sa fenwickom
		for (int i=1; i<=cnt; i++) {
			sort(deltas[i].begin(), deltas[i].end());
			for (auto [t, p, v] : deltas[i]) {
				if (v == 0) {
					if (qr[t] - ql[t] + 1 < l)
						continue;
					// cerr << "drvo sum " << qr[t] << ' ' << ql[t]+l-2 << '\n';
					qa[t] = drvo.sum(qr[t]) - drvo.sum(ql[t]+l-2);
				} else {
					// cerr << "drvo add " << p << ' ' << v << '\n';
					drvo.add(p, v);
				}
			}
		}
	}

	for (int i=0; i<q; i++)
		if (ql[i] != -1)
			cout << qa[i] << '\n';

}