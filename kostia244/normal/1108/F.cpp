#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;

int n, m, f, t, c, ans = 0;

class UFDS {
private:
	vi r, p;
public:
	UFDS(int n) {
		r.assign(n + 1, 0);
		p.resize(n + 1);
		for(int i = 0; i <= n; i++)
		p[i] = i;
	}
	int parent(int i) {
		return (i == p[i] ? i : (p[i] = parent(p[i])));
	}
	bool sameset(int i, int j) {
		return parent(i) == parent(j);
	}
	bool unify(int i, int j) {
		int x = parent(i), y = parent(j);
		if(x == y)
		return false;
		if(r[x] > r[y]) {
			p[y] = x;
		} else {
			if(r[x] == r[y])
			r[y]++;
			p[x] = y;
		}
		return true;
	}
};

class Edge {
public:
	int from, to, weight;
	Edge(int _f = -1, int _t = -1, int _w = 0) :
			from(_f), to(_t), weight(_w) {
	}
	;
	bool operator<(const Edge& b) {
		return weight < b.weight;
	}
};

vector<Edge> g;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	UFDS st(n);
	for (int i = 0; i < m; i++) {
		cin >> f >> t >> c;
		g.emplace_back(f, t, c);
	}
	sort(g.begin(), g.end());
	for (int i = 0; i < g.size(); i++) {
		int j = i + 1, cnt = 1;
		while (j < m && g[j].weight == g[i].weight)
			j++, cnt++;
		for(int k = i; k < j; k++)
			if(st.sameset(g[k].from, g[k].to))
				cnt--;
		for(int k = i; k < j; k++)
				cnt -= st.unify(g[k].from, g[k].to);
		ans += cnt;
		i = j - 1;
	}
	cout << ans;
}