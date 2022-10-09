#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1'000'000'000'000'037;

// custom hash table
struct htable {
	vector<ll> content, table;
	int mask;

	htable() : table(8, -1), mask(3) {}

	void expand() {
		table = vector<ll>(table.size() * 4, -1);
		mask = 4*mask + 3;
		for (ll x : content)
			add_impl(x);
	}

	void add_impl(ll x) {
		int p = x & mask;
		while (table[p] != -1)
			p++;
		table[p] = x;
	}

	void add(ll x) {
		if (content.size() * 4 == table.size())
			expand();
		add_impl(x);
		content.push_back(x);
	}

	int count(ll x) const {
		int p = x & mask;
		while (table[p] != -1) {
			if (table[p] == x)
				return 1;
			p++;
		}
		return 0;
	}
};

htable dodato[150005], obrisano[150005];
vector<int> velicine;

void dodaj_velicinu(int x) {
	auto it = lower_bound(velicine.begin(), velicine.end(), x);
	if (it != velicine.end() && *it == x)
		return;
	velicine.push_back(x);
	int i = velicine.size() - 1;
	while (i > 0 && velicine[i-1] > velicine[i]) {
		swap(velicine[i-1], velicine[i]);
		i--;
	}
}

ll p[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	p[0] = 1;
	for (int i=1; i<300005; i++)
		p[i] = p[i-1] * 127 % MOD;

	int q;
	cin >> q;
	while (q--) {
		int t;
		string s;
		cin >> t >> s;

		if (t < 3) {
			if (s.size() > 150000)
				continue; // cool
			ll h = 0;
			for (char x : s)
				h = (h * 127 + x) % MOD;
			auto gde = t == 1 ? dodato : obrisano;
			gde[s.size()].add(h);
			dodaj_velicinu(s.size());
		} else {
			int ans = 0;
			for (int vel : velicine) {
				if (vel > (int)s.size())
					break;
				ll h = 0;
				for (int i=0; i<vel; i++)
					h = (h * 127 + s[i]) % MOD;

				for (int i=vel; i<=(int)s.size(); i++) {
					// proveri
					ans += dodato[vel].count(h) - obrisano[vel].count(h);
					// pomeri
					if (i == (int)s.size())
						break;
					h = h * 127 + s[i] - p[vel] * s[i-vel];
					h %= MOD;
					if (h < 0)
						h += MOD;
				}
			}

			cout << ans << '\n' << flush;
		}
	}
}