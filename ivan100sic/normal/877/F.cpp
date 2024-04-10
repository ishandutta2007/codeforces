#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, q;
ll a[100005];
ll z[100005];
int t[100005];

struct upit {
	int l, r, gl, id;

	bool operator< (const upit& other) const {
		return make_pair(gl, r) < make_pair(other.gl, other.r);
	}
} b[100005];

ll ans[100005];

struct custom_map {

	vector<pair<ll, int>> regis;
	vector<ll> uniques;

	vector<int> storage;
	vector<int> reidx_plus, reidx_minus, reidx;

	int m;

	void register_number(ll x, int id) {
		regis.push_back({x, id});
		uniques.push_back(x);
		uniques.push_back(x - k);
		uniques.push_back(x + k);
	}

	void unravel() {
		sort(uniques.begin(), uniques.end());
		uniques.resize(unique(uniques.begin(), uniques.end()) - uniques.begin());

		m = uniques.size();
				
		reidx_plus.resize(regis.size());
		reidx_minus.resize(regis.size());
		reidx.resize(regis.size());

		for (auto p : regis) {
			int x = lower_bound(uniques.begin(), uniques.end(), p.first + k)
				- uniques.begin();
			reidx_plus[p.second] = x;

			x = lower_bound(uniques.begin(), uniques.end(), p.first - k)
				- uniques.begin();
			reidx_minus[p.second] = x;

			x = lower_bound(uniques.begin(), uniques.end(), p.first)
				- uniques.begin();
			reidx[p.second] = x;
		}

		storage.resize(m, 0);
	}

	int& get(int id, int dir) {
		switch (dir) {
			case 1: return storage[reidx_plus[id]];
			case 0: return storage[reidx[id]];
			case -1: return storage[reidx_minus[id]];
		}
		return n;
	}
};

custom_map br;

int pl, pr;
ll sol;

inline void dodaj_desno(int x) {
	sol += br.get(x, -1);
	br.get(x, 0)++;
}

inline void izbaci_desno(int x) {
	br.get(x, 0)--;
	sol -= br.get(x, -1);
}

inline void dodaj_levo(int x) {
	sol += br.get(x, +1);
	br.get(x, 0)++;
}

inline void izbaci_levo(int x) {
	br.get(x, 0)--;
	sol -= br.get(x, +1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> t[i];
	}
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (t[i] == 2) {
			a[i] = -a[i];
		}
		z[i] = z[i-1] + a[i];
	}

	for (int i=0; i<=n; i++) {
		br.register_number(z[i], i);
	}
	br.unravel();

	cin >> q;
	for (int i=1; i<=q; i++) {
		cin >> b[i].l >> b[i].r;
		b[i].l--;
		b[i].gl = b[i].l / 316;
		b[i].id = i;
	}

	sort(b+1, b+q+1);

	pl = 0;
	pr = -1;

	for (int i=1; i<=q; i++) {
		while (pr < b[i].r) {
			dodaj_desno(++pr);
		}
		while (pl > b[i].l) {
			dodaj_levo(--pl);
		}

		while (pr > b[i].r) {
			izbaci_desno(pr--);
		}
		while (pl < b[i].l) {
			izbaci_levo(pl++);
		}

		ans[b[i].id] = sol;
	}

	for (int i=1; i<=q; i++) {
		cout << ans[i] << '\n';
	}


}