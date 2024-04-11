#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<17, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
struct node
{
	int mn = 0;
	node *l, *r;
	node() { l = nullptr; r = nullptr; mn = 0; }
	node(int x) { mn = x; l = nullptr; r = nullptr; }
};
typedef node* pnode;
deque<node> buffer;
pnode newnode(int x = 0) {
	buffer.emplace_back(x);
	return &buffer.back();
}
 
pnode merge(pnode l, pnode r)
{
	pnode ret = newnode();
	ret->mn = min(l?l->mn:0, r?r->mn:0);
	ret->l = l;
	ret->r = r;
	return ret;
}
 
pnode init(int l, int r)
{
	if(l == r) { return (newnode(0));}
 
	int mid = (l + r) >> 1;
	return merge(init(l, mid), init(mid + 1, r));
}
 
pnode update(int pos, int val, int l, int r, pnode nd)
{
	if(pos < l || pos > r) return nd;
	if(l == r) { return newnode(max(val, nd->mn)); }
 
	int mid = (l + r) >> 1;
	return merge(update(pos, val, l, mid, nd->l), update(pos, val, mid + 1, r, nd->r));
}
 
int query(int qL, int qR, int l, int r, pnode nd)
{
	if(qL <= l && r <= qR) return nd->mn;
	if(qL > r || qR < l) return 1<<30;
 
	int mid = (l + r) >> 1;
	return min(query(qL, qR, l, mid, nd->l), query(qL, qR, mid + 1, r, nd->r));
}
pnode roots[600600];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int M, K;
	cin >> n >> M >> K;
	vector<array<int, 3>> f;
	vector<int> z;
	for(int a, b, p; K--;) {
		cin >> a >> b >> p;
		z.push_back(a);
		z.push_back(b);
		f.push_back({p, a, b});
	}
	sort(all(z));
	vector<vector<array<int, 2>>> F(z.size()+1);
	for(auto &[p, a, b] : f) {
		a = lower_bound(all(z), a)-z.begin()+1;
		b = lower_bound(all(z), b)-z.begin()+1;
		//cout << p << " " << a << " " << b << endl;
		F[b].push_back({p, a});
	}
	pnode root = init(1, n);
	for(int i = 0; i <= z.size(); i++) {
		for(auto [x, y] : F[i]) {
			//cout << x << ":=" << y << endl;
			root = update(x, y, 1, n, root);
		}
		roots[i] = root;
		//cout << i << " " << z[i] << " : ";for(int i = 1; i <= n; i++) cout << query(i, i, 1, n, root) << " "; cout << endl;
	}
	for(int a, b, x, y; M--;) {
		cin >> a >> b >> x >> y;
		x = lower_bound(all(z), x)-z.begin()+1;
		y = upper_bound(all(z), y)-z.begin();
		//cout << y << " " << z.size() << endl;
		if(x > y) cout << "no" << endl;
		else cout << (query(a, b, 1, n, roots[y])>=x?"yes":"no") << endl;
	}
}