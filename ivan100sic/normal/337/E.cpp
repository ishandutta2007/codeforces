#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 1000000;

int f[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {
		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

map<ll, int> factor(ll x) {
	map<ll, int> v;
	for (int p : prosti) {
		if (x % p == 0) {
			int c = 0;
			while (x % p == 0) {
				x /= p;
				c++;
			}
			v[p] = c;
		}			
	}

	if (x > 1) {
		v[x] = 1;
	}
	return v;
}

int n;
map<ll, int> v[8];

int zbir(const map<ll, int>& m) {
	int z = 0;
	for (auto [x, y] : m)
		z += y;
	return z;
}

map<ll, int> proizvod(const map<ll, int>& a, map<ll, int> b) {
	for (auto [x, y] : a)
		b[x] += y;
	return b;
}

map<ll, int> lcm(const map<ll, int>& a, map<ll, int> b) {
	for (auto [x, y] : a)
		b[x] = max(b[x], y);
	return b;
}

map<ll, int> kolicnik(map<ll, int> a, const map<ll, int>& b) {
	for (auto [x, y] : b)
		a[x] -= y;
	return a;
}

struct opcija {
	int cvorova;
	map<ll, int> root;
};

vector<opcija> moze[256];

vector<vector<int>> bell(int mask) {
	vector<vector<int>> res = {{}};
	for (int i=0; i<n; i++) {
		if (mask & (1 << i)) {
			vector<vector<int>> tmp;
			for (auto v : res) {
				// dodaj postojecoj grupi
				for (int& x : v) {
					x += 1 << i;
					tmp.push_back(v);
					x -= 1 << i;
				}
				// dodaj novu grupu
				auto w = v;
				w.push_back(1 << i);
				tmp.emplace_back(move(w));
			}
			swap(tmp, res);
		}
	}
	return res;
}

void min_add(map<int, map<ll, int>>& q, int key, const map<ll, int>& val) {
	auto it = q.find(key);
	if (it == q.end()) {
		q[key] = val;
	} else {
		if (key < it->first) {
			it->second = val;
		}
	}
}

template<class T>
void pick_indices(const vector<int>& sizes, int idx, vector<int>& tmp, T cb) {
	if (idx == (int)sizes.size()) {
		cb(tmp);
		return;
	}
	tmp.push_back(0);
	for (int i=0; i<sizes[idx]; i++) {
		tmp.back() = i;
		pick_indices(sizes, idx+1, tmp, cb);
	}
	tmp.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		ll x;
		cin >> x;
		v[i] = factor(x);
	}

	for (int mask=1; mask<(1<<n); mask++) {
		if (mask == (mask & -mask)) {
			int i = 31 - __builtin_clz(mask);
			int prost = v[i].size() == 1 && v[i].begin()->second == 1;
			moze[mask] = {opcija{zbir(v[i]) + !prost, v[i]}};
			continue;
		}

		map<int, map<ll, int>> q;
		auto b = bell(mask);
		for (auto w : b) {
			if (w.size() == 1)
				continue;
			vector<int> tmp, sizes;
			for (int x : w)
				sizes.push_back(moze[x].size());
			auto cb = [&](const vector<int>& picks) {
				int m = picks.size();
				map<ll, int> pr; int pr_cv = 0;
				for (int i=0; i<m; i++) {
					const auto& tmp = moze[w[i]][picks[i]].root;
					int tmp_cv = moze[w[i]][picks[i]].cvorova;
					pr_cv += tmp_cv;
					pr = proizvod(pr, tmp);
				}
				min_add(q, pr_cv + 1, pr);

				// izaberi jednog da ti bude root
				for (int i=0; i<m; i++) {
					if (w[i] != (w[i] & -w[i]))
						continue;

					const auto& tmp = moze[w[i]][picks[i]].root;
					int tmp_cv = moze[w[i]][picks[i]].cvorova;

					auto ostali = kolicnik(pr, tmp);

					if (lcm(ostali, tmp) == tmp) {
						min_add(q, pr_cv - tmp_cv + 1 + zbir(kolicnik(tmp, ostali)), tmp);
					}
				}
			};
			pick_indices(sizes, 0, tmp, cb);
		}

		for (auto [k, v] : q) {
			moze[mask].push_back(opcija{k, v});
		}

		cerr << "naj " << mask << ' ' << q.begin()->first << '\n';
	}

	int sol = 1e9;
	for (auto [k, v] : moze[(1 << n) - 1]) {
		sol = min(sol, k);
	}
	cout << sol << '\n';

}