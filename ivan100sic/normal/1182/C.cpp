#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool is_vowel(char x) {
	if (x == 'a') return true;
	if (x == 'e') return true;
	if (x == 'i') return true;
	if (x == 'o') return true;
	if (x == 'u') return true;
	return false;
}

struct rec {
	string s;
	int x;
	char y;
};

rec sredi(string s) {
	rec t;
	t.x = 0;
	t.y = 0;
	for (char x : s) {
		if (is_vowel(x)) {
			t.x++;
			t.y = x;
		}
	}
	t.s = move(s);
	return t;
}

map<pair<int, char>, vector<rec>> mp;
map<int, vector<rec>> pending_by_len;
set<int> g2lens;
vector<pair<rec, rec>> parovi;
vector<vector<rec>> sols;

void add_pending(rec r) {
	pending_by_len[r.x].push_back(r);
	if (pending_by_len[r.x].size() == 2)
		g2lens.insert(r.x);
}

void rem_pending(int len) {
	pending_by_len[len].pop_back();
	if (pending_by_len[len].size() == 1)
		g2lens.erase(len);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		rec r = sredi(s);
		// cerr << r.s << ' ' << r.x << ' ' << r.y << '\n';
		mp[{r.x, r.y}].push_back(r);
	}

	// napravi parove
	for (const auto& p : mp) {
		for (int i=0; i+1<(int)p.second.size(); i+=2) {
			parovi.push_back({p.second[i], p.second[i+1]});
		}
		if (p.second.size() % 2) {
			add_pending(p.second.back());
		}
	}

	// zadovolji parove
	while (parovi.size()) {
		auto [u, v] = parovi.back();
		parovi.pop_back();

		if (g2lens.size()) {
			int len = *g2lens.begin();

			auto U = pending_by_len[len][pending_by_len[len].size() - 2];
			auto V = pending_by_len[len][pending_by_len[len].size() - 1];
			sols.push_back({U, u, V, v});

			rem_pending(len);
			rem_pending(len);
		} else {
			add_pending(u);
			add_pending(v);
		}
	}

	cout << sols.size() << '\n';
	for (auto q : sols) {
		cout << q[0].s << ' ' << q[1].s << '\n';
		cout << q[2].s << ' ' << q[3].s << '\n';
	}
}