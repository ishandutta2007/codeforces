#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class UFDS {
private:
	vector<int> p, rank, setSizes;
public:
	int numSets;
	UFDS(int N) {
		numSets = N;
		rank.assign(N, 0);
		p.assign(N, 0);
		for (int i = 0; i < N; i++)
			p[i] = i;
		setSizes.assign(N, 1);
	}
	int findSet(int i) {
		return (p[i] == i) ? i : p[i] = findSet(p[i]);
	}
	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}
	void unionSet(int i, int j) {
		if (!isSameSet(i, j)) {
			int x = findSet(i), y = findSet(j);
			if (rank[x] > rank[y]) {
				setSizes[findSet(x)] += setSizes[findSet(y)];
				p[y] = x;
			} else {
				setSizes[findSet(y)] += setSizes[findSet(x)];
				p[x] = y;
				if (rank[x] == rank[y])
					rank[y]++;
			}
			numSets--;
		}
	}
	int setSize(int i) {
		return setSizes[findSet(i)];
	}
	int numDisjointSets() {
		return numSets;
	}
};


int n, m, k, u, v, x, tark, dp[501][501];
vi c, type;
int main() {
	doin();
	cin >> n >> m >> k;
	tark = k;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			dp[i][j] = 1e9 * (i != j);
	UFDS checker(n+1);
	c.resize(k + 1);
	type.resize(n + 1);
	for (int i = 1; i <= k; i++)
		cin >> c[i], tark -= c[i] == 0;
	u = 1;
	v = 0;
	for (int i = 1; i <= n; i++) {
		type[i] = u;
		if (++v == c[u])
			u++, v = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> x;
		if (x == 0)
			checker.unionSet(u, v);
		if (dp[type[u]][type[v]] > x)
			dp[type[u]][type[v]] = x;
		if (dp[type[v]][type[u]] > x)
			dp[type[v]][type[u]] = x;

	}
	u = 1;
	v = 0;
	for (int i = 1; i <= n; i++) {
		if (type[i] == type[i-1] && !checker.isSameSet(i, i-1))
			return cout << "No", 0;
	}
	cout << "Yes\n";
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			for (int _K = 1; _K <= k; _K++)
				dp[j][_K] = min(dp[j][_K], dp[j][i] + dp[i][_K]);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++)
			cout << (dp[i][j] != 1000000000 ? dp[i][j] : -1) << " ";
		cout << "\n";
	}
	return 0;
}