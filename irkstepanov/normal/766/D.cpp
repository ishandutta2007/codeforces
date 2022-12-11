#include <bits/stdc++.h>

#define sz(a) (int)(a).size()
#define pb push_back
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int n;

vector<int> parent;

pii get(int v)
{
	if (parent[v] >= n) {
		return {v, parent[v]};
	}
	pii ans = get(parent[v]);
	parent[v] = ans.first;
	return ans;
}

void unite(int u, int v)
{
	parent[v] = u;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("wa");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int m, q;
	cin >> n >> m >> q;

	parent.resize(2 * n);
	for (int i = 0; i < n; ++i) {
		parent[i] = i + n;
	}

	vector<pii> sons(2 * n);
	for (int i = n; i < 2 * n; ++i) {
		sons[i] = {i - n, -1};
	}

	map<string, int> mapa;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		mapa[s] = i;
	}

	while (m--) {
		int type;
		cin >> type;
		string x, y;
		cin >> x >> y;
		int u = mapa[x], v = mapa[y];
		pii a = get(u), b = get(v);
		if (a.second == b.second) {
			if (type == 1 && a.first != b.first) {
				cout << "NO\n";
			} else if (type == 2 && a.first == b.first) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
			}
			continue;
		}
		cout << "YES\n";
		int p, q;
		if (sons[a.second].first == a.first) {
			p = sons[a.second].second;
		} else {
			p = sons[a.second].first;
		}
		if (sons[b.second].first == b.first) {
			q = sons[b.second].second;
		} else {
			q = sons[b.second].first;
		}
		if (type == 1) {
			unite(a.first, b.first);
			if (q == -1) {
				continue;
			}
			if (p == -1) {
				if (sons[a.second].first == a.first) {
					sons[a.second].second = q;
				} else {
					sons[a.second].first = q;
				}
				parent[q] = a.second;
			} else {
				unite(p, q);
			}
		} else {
			if (p == -1) {
				if (sons[a.second].first == a.first) {
					sons[a.second].second = b.first;
				} else {
					sons[a.second].first = b.first;
				}
				parent[b.first] = a.second;
			} else {
				unite(p, b.first);
			}
			if (q != -1) {
				unite(a.first, q);
			}
		}
	}

	while (q--) {
		string x, y;
		cin >> x >> y;
		int u = mapa[x], v = mapa[y];
		pii a = get(u), b = get(v);
		if (a.second != b.second) {
			cout << "3\n";
		} else if (a.first == b.first) {
			cout << "1\n";
		} else {
			cout << "2\n";
		}
	}

}