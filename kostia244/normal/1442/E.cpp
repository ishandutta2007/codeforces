#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
struct node {
	multiset<int> ch[3];
	int col;
	array<int, 2> ans;
	node(int col = 2) : col(col), ans{1<<20, 1<<20} {
		if(col != 1) ans[0] = 1;
		if(col != 0) ans[1] = 1;
	}
	void upd_child(node &c, int add) {
		if(add) {
			if(c.ans[0] < c.ans[1]) {
				ch[0].insert(c.ans[0]);
			} else if(c.ans[0] > c.ans[1]) {
				ch[1].insert(c.ans[1]);
			} else {
				ch[2].insert(c.ans[1]);
			}
		} else {
			if(c.ans[0] < c.ans[1]) {
				ch[0].erase(ch[0].find(c.ans[0]));
			} else if(c.ans[0] > c.ans[1]) {
				ch[1].erase(ch[1].find(c.ans[1]));
			} else {
				ch[2].erase(ch[2].find(c.ans[1]));
			}
		}
		recalc();
	}
	template<int p>
	int get_max() {
		return ch[p].empty() ? -69 : *ch[p].rbegin();
	}
	void recalc(int dbg = 0) {
		ans[0] = ans[1] = 1<<20;
		if(ch[0].empty() && ch[1].empty() && ch[2].empty()) {
			if(col != 1) ans[0] = 1;
			if(col != 0) ans[1] = 1;
		} else {
			if(col != 1) ans[0] = max({get_max<0>(), get_max<1>()+1, get_max<2>()});
			if(col != 0) ans[1] = max({get_max<0>()+1, get_max<1>(), get_max<2>()});
		}
	}
};
const int maxn = 1<<18;
int n, a[maxn];
vector<int> g[maxn];
node dp[maxn];
void init(int v) {
	dp[v] = node(a[v]);
	for(int i : g[v]) {
		g[i].erase(find(all(g[i]), v));
		init(i);
		dp[v].upd_child(dp[i], 1);
	}
}
int ans;
void calc(int v, node &pdp) {
	if(v) dp[v].upd_child(pdp,1);
	for(int i = 0; i < 2; i++)
	ans = min(ans, dp[v].ans[i]);
	for(int i : g[v]) {
		dp[v].upd_child(dp[i], 0);
		calc(i, dp[v]);
		dp[v].upd_child(dp[i], 1);
	}
	if(v) dp[v].upd_child(pdp, 0);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(--a[i] == -1) a[i] =2;
			g[i].clear();
		}
		for(int f, t, i = 1; i < n; i++) {
			cin >> f >> t;--f,--t;
			g[f].push_back(t);
			g[t].push_back(f);
		}
		ans = 1<<20;
		init(0);
		node trash;
		calc(0, trash);
		cout << ans << '\n';
	}
	return 0;
}