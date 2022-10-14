#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 7 * 17 * (1 << 23) + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, targ, cnt = 0;
vvi g;
vi sz, maxch, comp, p, h;
bitset<200200> cent;
void pre(int v, int pr) {
	p[v] = pr;
	for (auto i : g[v])
		if (i != pr) {
			h[i] = h[v] + 1;
			pre(i, v);
		}
}
void sizes(int v, int p) {
	sz[v] = 1;
	maxch[v] = 0;
	comp.pb(v);
	for (auto i : g[v]) {
		if (i == p || cent.test(i))
			continue;
		sizes(i, v);
		sz[v] += sz[i];
		maxch[v] = max(maxch[v], sz[i]);
	}
}
int get(int v) {
	if (++cnt > 36)
		exit(-1);
	cout << "d " << v << "\n";
	cout.flush();
	int t;
	cin >> t;
	if (t == 0) {
		cout << "! " << v << "\n";
		cout.flush();
		exit(0);
	}

	if (h[v]+t != targ)
		return p[v];
	if (++cnt > 36)
		exit(-1);
	cout << "s " << v << "\n";
	cout.flush();
	cin >> t;
	return t;
}
void decompose(int v = 1) {
	comp.clear();
	sizes(v, v);
	int c = comp[0];
	for (auto i : comp) {
		maxch[i] = max(maxch[i], (int) comp.size() - sz[i]);
		if (maxch[i] < maxch[c])
			c = i;
	}
	cent.set(c);
	if (comp.size() == 1) {
		cout << "! " << v << "\n";
		cout.flush();
		exit(0);
	}
	int x = get(c);
	decompose(x);
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	g.resize(n + 1);
	h.resize(n + 1);
	p.resize(n + 1);
	sz.resize(n + 1);
	maxch.resize(n + 1);
	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	if (++cnt > 36)
		exit(-1);
	cout << "d 1\n";
	cout.flush();
	cin >> targ;
	if (targ == 0) {
		cout << "! 1\n";
		cout.flush();
		return 0;
	}
	pre(1, 1);
	decompose();
	return 0;
}