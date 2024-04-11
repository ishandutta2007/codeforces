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
const int maxn = 1<<19, mod = (119<<23)+1, lg = 19;
template<typename T>
struct segtree {
	T tree[maxn];
	int n;
	void init(int _n) {
		n = _n;
		for(int i = 0; i < n; i++) tree[n+i] = T();
		for(int i = 0; i < n; i++) tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	void set(int i, T v) {
		for(tree[i+=n] = v; i>>=1;) tree[i] = tree[i<<1] + tree[i<<1|1];
	}
	T get(int l, int r) {
		T res = T();
		for(l += n, r += n + 1; l < r; l>>=1, r>>=1) {
			if(l&1) res = res + tree[l++];
			if(r&1) res = res + tree[--r];
		}
		return res;
	}
};
template<typename T>
struct node {
	int mx;
	T val;
	node(int mx = -(1<<30)) : mx(mx) {}
	node(int mx, T val) : mx(mx), val(val)  {}
	node operator+(const node& b) {return mx > b.mx ? *this : b;}
};
segtree<node<bool>> st;
segtree<node<array<int, 3>>> st3;
segtree<node<array<int, 4>>> st4;
int n, q, a[maxn], fk[maxn], mxpos[maxn], mnpos[maxn];
void fuck(int i) {
	if(fk[i]++ == 0) st.set(i, node<bool>());
}
void unfuck(int i) {
	if(--fk[i] == 0) st.set(i, node<bool>(i));
}
void solve() {
	st.init(n);
	st3.init(n);
	st4.init(n);
	
	vector<int> mn, mx, mnq, mxq;
	for(int i = 0; i < n; i++) {
		while(!mnq.empty()&&a[mnq.back()]>a[i]) unfuck(mnq.back()), mnq.pop_back();
		while(!mxq.empty()&&a[mxq.back()]<a[i]) unfuck(mxq.back()), mxq.pop_back();
		while(!mn.empty()&&a[mn.back()]>=a[i]) mn.pop_back();
		while(!mx.empty()&&a[mx.back()]<=a[i]) mx.pop_back();
		if(!mn.empty()&&!mx.empty()) {
			node<bool> v = st.get(0, min(mn.back(), mx.back()));
			int pos = v.mx;
			if(v.mx != -1<<30) {//good
				int a = *lower_bound(all(mn), pos);
				int b = *lower_bound(all(mx), pos);
				if(a > b) swap(a, b);
				st4.set(i, {pos, {pos, a, b, i}});
			}
		}
		node<array<int, 3>> A, b;
		if(!mn.empty()&&mxpos[mn.back()]!=-1) A = {mxpos[mn.back()], {mxpos[mn.back()], mn.back(), i}};
		if(!mx.empty()&&mnpos[mx.back()]!=-1) b = {mnpos[mx.back()], {mnpos[mx.back()], mx.back(), i}};
		st3.set(i, A+b);
		if(!mn.empty()) mnpos[i] = mn.back();
		else mnpos[i] = -1;
		if(!mx.empty()) mxpos[i] = mx.back();
		else mxpos[i] = -1;
		mn.push_back(i);
		mx.push_back(i);
		mnq.push_back(i);
		mxq.push_back(i);
		fuck(i), fuck(i);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 0; i < n; i++) cin >> a[i];
	solve();
	int l, r;
	node<array<int, 4>> x;
	node<array<int, 3>> y;
	while(q--) {
		cin >> l >> r, --l, --r;
		x = st4.get(l, r), y = st3.get(l, r);
		if(x.mx >= l)
			cout << "4\n" << 1+x.val[0] << " " << 1+x.val[1] << " " << 1+x.val[2] << " " << 1+x.val[3] << '\n';
		else if(y.mx >= l)
			cout << "3\n" << 1+y.val[0] << " " << 1+y.val[1] << " " << 1+y.val[2] << '\n';
		else cout << "0\n\n";
	}
}