#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
bool v[1000005];
vector<vector<int>> e[1000005];

int q[1000005];

void spoji(vector<int> a, vector<int> b) {
	vector<int> c;
	for (size_t i=0; i<a.size(); i++) {
		c.push_back(a[i]);
		c.push_back(b[i]);
	}
	for (size_t i=0; i<c.size(); i++) {
		q[c[i]] = c[(i+1) % c.size()];
	}
}

void upleti(vector<int> a) {
	for (size_t i=0; i<a.size(); i++) {
		q[a[i]] = a[(i + a.size() / 2 + 1) % a.size()];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			vector<int> g;
			int x = i;
			do {
				v[x] = true;
				g.push_back(x);
				x = a[x];
			} while (x != i);
			e[g.size()].push_back(g);
		}
	}
	for (int i=1; i<=n; i++) {
		if (i % 2) {
			while (e[i].size()) {
				upleti(e[i].back());
				e[i].pop_back();
			}
		} else {
			if (e[i].size() % 2) {
				cout << -1;
				return 0;
			}
			while (e[i].size()) {
				auto a = e[i].back();
				e[i].pop_back();
				auto b = e[i].back();
				e[i].pop_back();
				spoji(a, b);
			}
		}
			
	}
	for (int i=1; i<=n; i++) {
		cout << q[i] << ' ';
	}
}