#include <bits/stdc++.h>
using namespace std;

int n, T;

struct task {
	int g, t, id;

	bool operator< (const task& other) const {
		if (t != other.t) {
			return t < other.t;
		}
		return make_pair(g, id) < make_pair(other.g, other.id);
	}
} a[200005];

set<task> hu, hl;
int total;

void fix() {
	while (total < T && hl.size()) {
		auto tmp = *hl.begin();

		if (total + tmp.t > T) {
			break;
		}

		total += tmp.t;
		hu.insert(tmp);
		hl.erase(tmp);
	}
}

vector<task> toremove[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> T;
	for (int i=1; i<=n; i++) {
		cin >> a[i].g >> a[i].t;
		a[i].id = i;
	}

	for (int i=1; i<=n; i++) {
		toremove[a[i].g].push_back(a[i]);
	}

	for (int i=1; i<=n; i++) {
		hl.insert(a[i]);
	}

	int best = 0;

	for (int i=1; i<=n; i++) {
		fix();
		if ((int)hu.size() > best) {
			best = min(i, (int)hu.size());
		}

		// obrisi sve ove sto nece da valjaju
		for (task t : toremove[i]) {
			hl.erase(t);
			if (hu.count(t)) {
				hu.erase(t);
				total -= t.t;
			}
		}
	}

	cout << best << '\n' << best << '\n';

	hu.clear();
	hl.clear();

	for (int i=best; i<=n; i++) {
		for (task t : toremove[i]) {
			hu.insert(t);
		}
	}

	while (best > 0) {

		if (hu.size() == 0) {
			cerr << "err\n";
			break;
		}

		cout << hu.begin()->id << ' ';
		hu.erase(hu.begin());
		best--;
	}

}