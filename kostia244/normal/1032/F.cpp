#include<bits/extc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<19, mod = 998244353;
vi g[maxn];
int n;
array<ll, 3> dfs(int v) {
	array<ll, 3> ans{};
	ans[0] = 1;
	for(auto i : g[v]) {
		//cout << v << " " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
		g[i].erase(find(all(g[i]), v));
		auto t = dfs(i);
		array<ll, 3> nw;
		nw[0] = (ans[0]*(t[0]+t[2]))%mod;
		nw[1] = (ans[0]*t[2] + ans[1]*(t[0]+t[2]+t[2]))%mod;
		nw[2] = (ans[2]*(t[0]+t[2]+t[2]) + (ans[1]+ans[0])*(t[0]+t[1]))%mod;
		ans = nw;
	}
	//cout << v << " " << ans[0] << " " << ans[1] << " " << ans[2] << endl;
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	auto t = dfs(1);
	cout << (t[0]+t[2])%mod << endl;
}