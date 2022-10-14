#pragma GCC optimize("O3")
#pragma GCC target("avx,avx2,sse,fma,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e6 + 20, mlg = 18, mod = 1e9 + 7;
mt19937 rng(1022327586883856909ll);//chrono::steady_clock::now().time_since_epoch().count());
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
map<int, int> dp;
int f(int a) {
	if(dp.count(a)) return dp[a];
	set<int> t;
	for(int i = 1; i < 30; i++) {
		int x = (a>>i) | (a&(((1<<i)-1)>>1));
		if(a!=x)
			t.insert(f(x));
	}
	int b = 0;
	while(t.count(b)) b++;
	return dp[a] = b;
}
map<int, int> tp;
void factor(int x) {
	for(int d = 2; d*d <= x; d++) {
		if(x%d) continue;
		int c = 0;
		while(x%d==0)x/=d, c++;
		tp[d]|=1<<(c-1);
	}
	if(x>1) {
		tp[x]|=1;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, t;
	cin >> n;
	while(n--) cin >> t, factor(t);
	int cur = 0;
	for(auto i : tp) cur ^= f(i.second);
	cout << (cur?"Mojtaba":"Arpa");
	return 0;
}