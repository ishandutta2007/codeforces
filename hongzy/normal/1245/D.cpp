#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 2010;
struct node {
	int c, k, x, y;
} a[N];
struct edge {
	int u, v; ll w;
	bool operator < (const edge &b) const {
		return w < b.w;
	}
};
vector<edge> vec;
int n, f[N];
ll cost[N], Min[N];
ll ab(int x) {
	return x > 0 ? x : -x;
}
ll dis(int x, int y) {
	return ab(a[x].x - a[y].x) + ab(a[x].y - a[y].y);
}
int find(int u) {
	return u == f[u] ? u : f[u] = find(f[u]);
}
vector<pii> lk;
vector<int> bu;
bool vis[N];
int main() {
	ucin();
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> a[i].x >> a[i].y;
	for(int i = 1; i <= n; i ++) cin >> a[i].c;
	for(int i = 1; i <= n; i ++) cin >> a[i].k;
	for(int i = 1; i <= n; i ++) {
		for(int j = i + 1; j <= n; j ++) {
			vec.pb((edge) {i, j, (a[i].k + a[j].k) * dis(i, j)});
		}
		f[i] = i; cost[i] = a[i].c; Min[i] = a[i].c;
	}
	sort(vec.begin(), vec.end());
	for(edge p : vec) {
		int u = find(p.u), v = find(p.v);
		if(u == v) continue ;
		if(cost[u] + cost[v] > p.w + cost[u] + cost[v] - Min[u] - Min[v] + min(Min[u], Min[v])) {
			cost[v] = p.w + cost[u] + cost[v] - Min[u] - Min[v] + min(Min[u], Min[v]);
			f[u] = v; Min[v] = min(Min[v], Min[u]); lk.pb(pii(p.u, p.v));
		}
	}
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		ans += cost[find(i)]; cost[find(i)] = 0;
		if(Min[find(i)] == a[i].c) {
			bu.pb(i);
			Min[find(i)] = -1;
		}
	}
	cout << ans << endl;
	cout << bu.size() << endl;
	for(int v : bu) cout << v << ' ';
	cout << endl << lk.size() << endl;
	for(pii v : lk) cout << v.first << ' ' << v.second << endl;
	return 0;
}