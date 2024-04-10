/*
#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

map<pii, pii> mp;

const int sz = 100;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist1(1, 5000);
	uniform_int_distribution<> dist2(1, 10000);

	while (mp.size()<10000) {
		int x = dist1(gen), y = dist1(gen);
		x^y
		if (x==y) continue;
		if (x>y) swap(x, y);
		mp[{x^y, (x+y)%5000}] = {dist2(gen), dist2(gen)};
	}

	cout << 5000 << ' ' << 10000 << '\n';
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		if ((it->va).va == (it->va).vb) continue;
		cout << (it->va).va << ' ' << (it->va).vb << ' ' << (it->vb).va << ' ' << (it->vb).vb << '\n';
	}
}
*/

#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int N;
int deg[100010], par[100010];
bool chk[100010];
vector<int> G[100010], P[100010];
int X[100010], Y[100010], Z[100010];

void dfs(int st, int prv, int cur) {
	cout << cur << ' ';
	for (int nxt : P[cur]) {
		if (nxt == prv || nxt == st) continue;
		dfs(st, cur, nxt);
	}
}

int Find(int a) {
	if (par[a] == a) return a;
	return par[a] = Find(par[a]);
}
void Union(int a, int b) {
	if (Find(a) == Find(b)) return;
	par[Find(b)] = Find(a);
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while (t--) {
		cin >> N;

		for (int i=1; i<=N; i++) {
			par[i] = i; deg[i] = 0; chk[i] = false;
			G[i].clear(); P[i].clear();
		}

		for (int i=1; i<=N-2; i++) {
			cin >> X[i] >> Y[i] >> Z[i];
			deg[X[i]]++; G[X[i]].push_back(i);
			deg[Y[i]]++; G[Y[i]].push_back(i);
			deg[Z[i]]++; G[Z[i]].push_back(i);
		}

		vector<pii> v;
		queue<pii> q;
		for (int i=1; i<=N; i++) {
			if (deg[i] == 1) q.emplace(i, G[i].back());
		}

		while (!q.empty()) {
			pii tmp = q.front(); q.pop();
			v.push_back(tmp);
			chk[tmp.vb] = true;

			int idx;
			for (int i=0; i<3; i++) {
				if (i==0) idx = X[tmp.vb];
				if (i==1) idx = Y[tmp.vb];
				if (i==2) idx = Z[tmp.vb];

				if (Find(idx) != Find(tmp.va)) {
					P[idx].push_back(tmp.va);
					P[tmp.va].push_back(idx);
					Union(idx, tmp.va);
				}

				if (--deg[idx] != 1) continue;
				while (chk[G[idx].back()]) G[idx].pop_back();

				q.emplace(idx, G[idx].back());
			}
		}
		v.pop_back(); v.pop_back();

		int st;
		for (int i=1; i<=N; i++) if (P[i].size() == 1) st = i;

		dfs(st, 0, st);
		cout << '\n';
		for (int i=0; i<v.size(); i++) cout << v[i].vb << ' ';
		cout << '\n';
	}
}