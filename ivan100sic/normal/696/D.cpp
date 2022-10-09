#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct aho_corasick {
	struct node {
		map<char, int> next;
		int link;

		node() : next(), link(0) {}
	};

	vector<node> b;

	aho_corasick() {
		b.emplace_back();
	}

	int trie_add(const string& s) {
		int y = 0;
		for (char x : s) {
			if (b[y].next.count(x)) {
				y = b[y].next[x];
			} else {
				y = b[y].next[x] = b.size();
				b.emplace_back();
			}
		}
		return y;
	}

	void bfs() {
		b[0].link = -1;
		basic_string<int> q = {0};
		size_t qs = 0;
		while (q.size() != qs) {
			int x = q[qs++];
			for (auto [c, y] : b[x].next) {
				int t = b[x].link;
				while (t != -1 && b[t].next.count(c) == 0)
					t = b[t].link;
				if (t != -1) {
					b[y].link = b[t].next[c];
				} else {
					b[y].link = 0;
				}
				q += y;
			}
		}
	}

	int jump(int x, char c) {
		while (x >= 0 && b[x].next.count(c) == 0) {
			x = b[x].link;
		}
		if (x == -1)
			return 0;
		else
			return b[x].next[c];
	}
};

struct mat {
	ll a[205][205];

	mat() {
		memset(a, 192, sizeof a);
	}

	mat operator* (const mat& b) const {
		mat t;
		for (int i=0; i<205; i++) {
			for (int j=0; j<205; j++) {
				for (int k=0; k<205; k++) {
					t.a[i][k] = max(t.a[i][k], a[i][j] + b.a[j][k]);
				}
			}
		}
		return t;
	}

	template<class U>
	mat operator^ (U arg) const {
		if (arg == 1)
			return *this;
		auto t = *this ^ (arg >> 1);
		t = t*t;
		if (arg & 1)
			t = t* *this;
		return t;
	}
};

int w[205], pos[205], w2[205], w3[205];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	aho_corasick ac;
	int n;
	ll l;
	cin >> n >> l;
	for (int i=0; i<n; i++)
		cin >> w[i];
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		pos[i] = ac.trie_add(s);
		w2[pos[i]] += w[i];
	}
	ac.bfs();
	int k = ac.b.size();
	for (int i=0; i<k; i++)
		for (int j=i; j!=-1; j=ac.b[j].link)
			w3[i] += w2[j];
	mat a;
	for (int i=0; i<k; i++) {
		for (char x='a'; x<='z'; x++) {
			int j = ac.jump(i, x);
			a.a[i][j] = w3[j];
		}
	}
	a = a ^ l;
	cout << *max_element(a.a[0], a.a[0] + k) << '\n';
}