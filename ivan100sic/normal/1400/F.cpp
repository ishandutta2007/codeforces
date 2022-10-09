// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct ahocorasick {
	struct node {
		map<char, int> next, hop;
		int link{0};
	};
	vector<node> b;
	bool done;
	ahocorasick() : b(1), done(false) {}
	int size() const { return b.size(); }

	int operator+= (const string& s) {
		int y = 0;
		for (char x : s) {
			auto it = b[y].next.find(x);
			if (it == b[y].next.end()) {
				it = b[y].next.insert(it, {x, b.size()});
				b.emplace_back();
			}
			y = it->second;
		}
		done = false;
		return y;
	}

	void bfs() {
		b[0].link = -1;
		vector<int> q(b.size());
		size_t qs = 0, qe = 1;
		while (qs != qe) {
			int x = q[qs++];
			for (auto [c, y] : b[x].next) {
				int t = b[x].link;
				while (t != -1 && !b[t].next.count(c))
					t = b[t].link;
				b[y].link = t != -1 ? b[t].next[c] : 0;
				q[qe++] = y;
			}
		}
		done = true;
	}

	int operator() (int x, char c) {
		if (!done) bfs();
		auto it = b[x].hop.find(c);
		if (it == b[x].hop.end()) {
			int t = x;
			while (t >= 0 && b[t].next.count(c) == 0)
				t = b[t].link;
			it = b[x].hop.insert(it, {c, t == -1 ? 0 : b[t].next[c]});
		}
		return it->second;
	}
} aca;

bool oksufiksi(string s, int x) {
	vector<int> z(s.size() + 1);
	for (int i=0; i<(int)s.size(); i++) {
		z[i+1] = z[i] + s[i] - 48;
	}
	for (int i=0; i<(int)s.size(); i++) {
		int y = z[s.size()] - z[i];
		if (y < x && x % y == 0) {
			return false;
		}
	}
	return true;
}

bool ban[5000];

void rek(string s, int sum, int x) {
	if (!oksufiksi(s, x)) {
		return;
	}

	if (sum == x) {
		ban[aca += s] = 1;
		return;
	}

	for (int c=1; c<=9; c++) {
		if (sum + c <= x) {
			rek(s + char(48 + c), sum + c, x);
		}
	}
}

int tranz[5000][10];

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	string s;
	int x;
	cin >> s >> x;
	rek("", 0, x);
	int k = aca.size();

	for (int i=0; i<k; i++) {
		for (int j=1; j<=9; j++) {
			tranz[i][j] = aca(i, j+48);
		}
	}

	vector<int> ol(k, 1e9);
	ol[0] = 0;
	for (char c : s) {
		vector<int> nu(k, 1e9);
		for (int j=0; j<k; j++) {
			int jj = tranz[j][c-48];
			if (!ban[jj]) {
				mn(nu[jj], ol[j]);
			}
			mn(nu[j], ol[j] + 1);
		}
		swap(ol, nu);
	}
	cout << *min_element(begin(ol), end(ol)) << '\n';
}