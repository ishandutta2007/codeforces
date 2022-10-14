#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 2e5 + 33, mlg = 17, mod = 1e9 + 7;
//using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct fenwick {
	vi tree;
	void init(int n) {
		tree.resize(n+1);
	}
	void upd(int l, int r, int x){
		upd(l,x);
		upd(r+1,x);
	}
	void upd(int i, int x){
		while(i < tree.size()) {
			tree[i] ^= x;
			i += i&-i;
		}
	}
	int get(int i) {
		int res = 0;
		while(i) {
			res^=tree[i];
			i -= i&-i;
		}
		return res;
	}
};
int n, q, arr[maxn], tsz;
vi tree[2*maxn];
fenwick a;
void insert(vi &a, int x) {
	for(auto i : a) x = min(x, i^x);
	if(x) a.pb(x);
}
void merge(vi &a, vi &b, vi &c) {
	a.clear();
	for(auto i : b)
		a.pb(i);
	for(auto i : c)
		insert(a, i);
}
void merge(vi &a, vi &b) {
	for(auto i : b)
		insert(a, i);
}
void init() {
	tsz=n-1;
	for(int i = 0; i < tsz; i++)
		tree[tsz+i] = {arr[i+1]^arr[i+2]};
	for(int i = tsz; i--;)
		merge(tree[i], tree[i<<1], tree[i<<1|1]);
}
void xset(int p, int x) {
	for(p+=tsz, tree[p] = {x^tree[p][0]}; p>>=1;)
		merge(tree[p], tree[p<<1], tree[p<<1|1]);
}
int get(int l, int r, int z) {
	vi ans;
//	cout << l << " " << r << " " << z << "\n";
	for(l += tsz, r+=tsz+1; l < r; l>>=1, r>>=1) {
		if(l&1) merge(ans, tree[l++]);
		if(r&1) merge(ans, tree[--r]);
	}
//	cout << ans.size() << " : ";for(auto i : ans) cout << i << " "; cout << "\n";
	insert(ans, z);
//	cout << ans.size() << " : ";for(auto i : ans) cout << i << " "; cout << "\n";
	return 1<<ans.size();
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	a.init(n);
	for(int t, i = 1; i <= n; i++) cin >> t, arr[i] = t, a.upd(i, i, t);
	init();
	int l, r, k, t;
	while(q--) {
		cin >> t >>l >> r;
		if(t==1) {
			cin >> k;
			a.upd(l, r, k);
			if(l-2>=0)
			xset(l-2, k);
			if(r-1<tsz)
			xset(r-1, k);
		} else {
//			cout << l << " " << r << "n\n";
			cout << get(l-1, r-2, a.get(l)) << "\n";
		}
	}
}