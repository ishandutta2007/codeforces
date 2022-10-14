#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;
//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937rng(chrono::steady_clock::now().time_since_epoch().count());

class UFDS {
	int ns;
	vi r, p;
public:
	UFDS(int n) {
		p.resize(n + 1);
		for(int i = 1; i <= n; i++) p[i] = i;
		r.assign(n + 1, 0);
		ns = n;
	}
	int parent(int i) {
		return (i == p[i] ? i : (p[i] = parent(p[i])));
	}
	bool sameset(int i , int j) {
		return parent(i) == parent(j);
	}
	void unify(int i, int j) {
		i = parent(i), j = parent(j);
		if(i != j) {
			if(r[i] > r[j])
				p[j] = i;
			else {
				p[i] = j;
				if(r[i] == r[j])
					r[j]++;
			}
		}
		ns--;
	}
	int numsets() {
		return ns;
	}
};

int n, m, sz;
vector<vi> g;
char bp[1005][1005];
vi in, oin, ans, topo;
char c;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	sz = n + m;
	in.resize(sz + 5, 0);
	oin.resize(sz + 5, 0);
	ans.resize(sz + 5, 0);
	g.resize(sz + 5);
	UFDS index(sz);
	for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c;
				bp[i][j] = c;
				if(c == '=') index.unify(i, n + j);
			}
		}
	for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				c = bp[i][j];
				if(c != '=' && index.sameset(i, n + j))
					return cout << "No", 0;
				if(c == '>')
					g[index.parent(n + j)].pb(index.parent(i));
				else if(c == '<')
					g[index.parent(i)].pb(index.parent(n + j));
			}
		}
	for(int i = 1; i <= sz; i++)
		if(index.parent(i) == i)
			for(auto& j : g[i])
				if(index.parent(j) == j)
					in[j]++;
	for(int i = 1; i <= sz; i++)
		if(in[i] == 0 && index.parent(i) == i)
			topo.pb(i), ans[i] = 1;
	int i = 0;
	while(i < topo.size()) {
		for(auto& to : g[topo[i]]) {
			if(index.parent(to) != to)
				continue;
			in[to]--;
			if(in[to] == 0)
				topo.pb(to), ans[to] = ans[topo[i]] + 1;
		}
		i++;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if(bp[i][j] == '=' && ans[index.parent(i)] != ans[index.parent(n + j)])
				return cout << "No", 0;
			if(bp[i][j] == '>' && ans[index.parent(i)] <= ans[index.parent(n + j)])
				return cout << "No", 0;
			if(bp[i][j] == '<' && ans[index.parent(i)] >= ans[index.parent(n + j)])
				return cout << "No", 0;
		}
	}

	cout << "Yes\n";
	for(int i = 1; i <= n; i++)
		cout << ans[index.parent(i)] << " ";
	cout << "\n";
	for(int i = 1; i <= m; i++)
		cout << ans[index.parent(n + i)] << " ";
}