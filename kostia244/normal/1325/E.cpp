#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<20, mod = (119<<23)+1;
int lp[maxn], m2[maxn], n;
vi pr;
void sieve() {
	m2[1] = 1;
	for(int i = 2; i < maxn; i++) {
		if(lp[i] == 0) lp[i] = m2[i] = i, pr.pb(i);
		else {
			int x = lp[i];
			if(m2[i/x]%x) m2[i] = m2[i/x]*x;
			else m2[i] = m2[i/x]/x;
		}
		for(int j = 0; j < pr.size() && pr[j] <= lp[i] && i*pr[j] < maxn; j++) lp[i*pr[j]] = pr[j];
	}
}
int ans = 1<<30;
vi g[maxn];
int dist[maxn], p[maxn];
void go(int v) {
	queue<int> q;
	pr.pb(1);
	for(auto i : pr) dist[i] = 1<<30, p[i] = -1;
	q.push(v), dist[v] = 0;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto &i : g[u]) {
			if(dist[i] == 1<<30) {
				dist[i] = dist[u] + 1, p[i] = u;
				q.push(i);
			} else if(i != p[u] && u != p[i]) {
				ans = min(ans, dist[u] + dist[i] + 1);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	sieve();
	cin >> n;
	set<int> hv;
	for(int t, i = 0; i < n; i++) {
		cin >> t;t = m2[t];
		if(t == 1) return cout << 1, 0;
		else if(hv.insert(t).second) {
			g[(t/lp[t])].pb((lp[t]));
			g[(lp[t])].pb((t/lp[t]));
		} else ans = 2;
	}
	for(auto i : pr) if(i < 1000) go(i);
	if(ans == 1<<30) ans = -1;
	cout << ans;
}