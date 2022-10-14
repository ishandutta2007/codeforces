//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const int mod = 1000000007;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ADD = 0;
struct segtree {
	int n;
	vi tree;
	void init(int sz) {
		n = sz;
		tree.resize(2*n+1);
	}
	void modify(int p, int x) {
		for(tree[p+=n] = x; p>>=1;)
			tree[p] = max(tree[p<<1], tree[p<<1|1]);
	}
	int get(int l, int r) {
		int ans = -ADD;
		for(l += n, r+= n+1; l<r;l>>=1, r>>=1) {
			if(l&1) ans = max(ans, tree[l++]);
			if(r&1) ans = max(ans, tree[--r]);
		}
		return ans;
	}
};
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	vector<pair<pair<int, int>, int>> a;
	vi ans;
	cin >> n;
	a.resize(n);
	ans.resize(n);
	for(int i = 0; i < n; i++)
		cin >> a[i].first.first >> a[i].first.second, a[i].second = i;
	sort(all(a));
	segtree x;
	x.init(n);
	int j;
	for(int i = n; i--;) {
		j = i;
		for(int x = 1<<17; x; x>>=1)
			if(j+x<n&&a[j+x].first.first<a[i].first.first+a[i].first.second) j+=x;
		ans[a[i].second] = 1 + ADD + x.get(i+1, j);
//		cout << i << " " << j << " " << x.get(i+1, j) <<"\n";
		ADD++;
		x.modify(i, ans[a[i].second] - ADD);
//		cout << i << " " << j << " " << ans[a[i].second] <<"\n";
	}
	for(int i = 0; i<n; i++) cout << ans[i]<< " ";
}