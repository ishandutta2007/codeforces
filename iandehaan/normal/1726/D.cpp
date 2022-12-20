#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 200'010

int par[MAXN];
int getPar(int x) {
	if (par[x] == x) return x;
	return par[x] = getPar(par[x]);
}
void Union(int x, int y) {
	par[getPar(x)] = getPar(y);
}

vector<pair<pii, int>> edges;
vector<int> others;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	srand(time(NULL));
	std::mt19937 rng { std::chrono::high_resolution_clock::now().time_since_epoch().count() };

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		
		edges.resize(m);
		others.resize(m - (n-1));
		rep(i, 0, m) {
			cin >> edges[i].first.first >> edges[i].first.second;
			edges[i].first.first--; edges[i].first.second--;
			edges[i].second = i;
		}

		string out;
		int best = 1e8;
		int numiters = 10;
		while (numiters--) {
			if (best == 2*n - m) break;

			rep(i, 0, n) par[i] = i;

			shuffle(all(edges), rng);

			int ind = 0;
			string medo;
			medo.resize(m);

			rep(i, 0, m) {
				int u = edges[i].first.first;
				int v = edges[i].first.second;
				if (getPar(u) == getPar(v)) {
					others[ind] = i;
					ind++;
					medo[edges[i].second] = '0';
				} else {
					Union(u, v);
					medo[edges[i].second] = '1';
				}
			}

			int med = n+1;

			rep(i, 0, n) par[i] = i;
			for (int extra : others) {
				int u = edges[extra].first.first;
				int v = edges[extra].first.second;
				if (getPar(u) != getPar(v)) {
					Union(u, v);
					med--;
				}
			}

			if (med < best) {
				best = med;
				out = medo;
			}

		}

		cout << out << '\n';
	}
}