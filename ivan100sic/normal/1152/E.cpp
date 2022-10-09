#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<int, multiset<int>> e;

int n;
int b[100005], c[100005];

list<int> euler(int x) {
	list<int> w;
	while (e[x].size()) {
		int y = *e[x].begin();
		w.push_back(y);
		e[x].erase(e[x].find(y));
		e[y].erase(e[y].find(x));
		// cerr << "edge " << x << ' ' << y << '\n';
		x = y;
	}
	// cerr << "stop\n";
	// for (int x : w)
	// 	cerr << x << " -> ";
	// cerr << "\n";
	for (auto it = w.begin(); it != w.end(); ++it) {
		auto v = euler(*it);
		w.splice(next(it), v);
	}
	// cerr << "returning\n";
	// for (int x : w)
	// 	cerr << x << " -> ";
	// cerr << "\n";
	return w;
}

void no() {
	cout << "-1\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n-1; i++)
		cin >> b[i];
	for (int i=0; i<n-1; i++)
		cin >> c[i];

	for (int i=0; i<n-1; i++) {
		if (b[i] > c[i])
			no();
		e[b[i]].insert(c[i]);
		e[c[i]].insert(b[i]);
	}

	basic_string<int> odd;
	for (auto& [x, v] : e) {
		if (v.size() % 2) {
			odd += x;
		}
	}
	if (odd.size() > 2)
		no();
	list<int> v;
	basic_string<int> w;
	if (odd.size() == 2) {
		int p = odd[0];
		int q = odd[1];
		e[p].insert(q);
		e[q].insert(p);
		v = euler(p);
		w = basic_string<int>(v.begin(), v.end());
		int idx = 0;
		for (int i=0; i<(int)w.size()-1; i++) {
			if (w[i] == p && w[i+1] == q) {
				idx = i+1;
			} else if (w[i] == q && w[i+1] == p) {
				idx = i+1;
			}
		}
		rotate(w.begin(), w.begin()+idx, w.end());
	} else {
		// cerr << "no odd\n";
		int p = e.begin()->first;
		int q = p;
		e[p].insert(q);
		e[q].insert(p);
		v = euler(p);
		w = basic_string<int>(v.begin(), v.end());
		int idx = 0;
		for (int i=0; i<(int)w.size()-1; i++) {
			if (w[i] == p && w[i+1] == q) {
				idx = i+1;
			} else if (w[i] == q && w[i+1] == p) {
				idx = i+1;
			}
		}
		rotate(w.begin(), w.begin()+idx, w.end());
	}

	if ((int)w.size() != n)
		no();

	for (int x : w)
		cout << x << ' ';
	cout << '\n';
}