#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
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
const int maxn = 1<<17, mod = (119<<23)+1, lg = 17;
struct node {
	int sum;
	node *l, *r;
	node(int x = 0) {sum = x; l=r=0;}
};
using pnode = node*;
deque<node> buffer;
pnode newnode(int x) {
	buffer.emplace_back(x);
	return &buffer.back();
}
pnode merge(pnode l, pnode r) {
	pnode t = newnode(l->sum+r->sum);
	t->l = l, t->r = r;
	return t;
}
pnode build(int l, int r) {
	if(l == r) return newnode(0);
	int mid = (l+r)>>1;
	return merge(build(l, mid), build(mid+1, r));
}
pnode upd(int l, int r, int i, int x, pnode rt) {
	if(i <l || i > r) return rt;
	if(l == r) return newnode(rt->sum + x);
	int mid = (l+r)>>1;
	return merge(upd(l, mid, i, x, rt->l), upd(mid+1, r, i, x, rt->r));
}
int kth(int l, int r, int k, pnode rt) {
	if(rt->sum < k) return 1<<30;
	if(l == r) return l;
	int mid = (l+r)>>1;
	if(rt->l->sum < k) return kth(mid+1, r, k-(rt->l->sum), rt->r);
	return kth(l, mid, k, rt->l);
}
pnode rt[maxn];
int n, a[maxn];
int solve(int k) {
	int p = 1, ans = 0;
	while(p <= n) {
		p = kth(1, n, k+1, rt[p]);
		ans++;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	rt[n+1] = build(1, n);
	map<int, int> lst;
	for(int i = n; i; i--) {
		rt[i] = rt[i+1];
		if(lst.count(a[i])) rt[i] = upd(1, n, lst[a[i]], -1, rt[i]); 
		rt[i] = upd(1, n, lst[a[i]] = i, 1, rt[i]);
	}
	for(int k = 1; k <= n; k++) {
		cout << solve(k) << " ";
	}
}