#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

struct DSU {
	vector<int> parent;
	DSU(int m) {
		parent.resize(m + 1);
		for(int i = 0; i <= m; ++i) {
			parent[i] = i;
		}
	}
	int find(int a) {
		if(a == parent[a]) {
			return a;
		}
		return parent[a] = find(parent[a]);
	}
	void uni(int a, int b) {
		parent[find(a)] = find(b);
	}
};

int main() {
	// 1) read input
	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int m = *max_element(a.begin(), a.end());
	// 2) prime sieve
	vector<vector<int>> prime_divisors(m + 2);
	for(int p = 2; p <= m + 1; ++p) {
		if(prime_divisors[p].empty()) {
			for(int j = p; j <= m + 1; j += p) {
				prime_divisors[j].push_back(p);
			}
		}
	}
	// 3) DSU, find initial connected components
	DSU dsu(m + 2);
	for(int x : a) {
		for(int p : prime_divisors[x]) {
			dsu.uni(x, p);
		}
	}
	// 4) DSU, find edges of cost 1
	set<pair<int,int>> edges;
	for(int x : a) {
		vector<int> nodes = prime_divisors[x+1];
		nodes.push_back(x);
		for(int& node : nodes) {
			node = dsu.find(node);
		}
		for(int i = 0; i < (int) nodes.size(); ++i) {
			for(int j = i + 1; j < (int) nodes.size(); ++j) {
				int one = nodes[i];
				int two = nodes[j];
				if(one != two) {
					if(one > two) {
						swap(one, two);
					}
					edges.insert({one, two});
				}
			}
		}
	}
	debug() << imie(edges);
	cerr << imie(edges.size()) << endl;
	// 5) answer queries
	while(q--) {
		int s, t;
		scanf("%d%d", &s, &t);
		--s;
		--t;
		s = dsu.find(a[s]);
		t = dsu.find(a[t]);
		if(s == t) {
			puts("0");
		}
		else if(edges.count({min(s, t), max(s, t)})) {
			puts("1");
		}
		else {
			puts("2");
		}
	}
}