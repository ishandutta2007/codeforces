#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4")
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = max(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return max(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};
struct node
{
	int mul;
	node *l, *r;
	node() { l = nullptr; r = nullptr; mul = 1; }
	node(int x) { mul = x; l = nullptr; r = nullptr; }
};

typedef node* pnode;
deque<node> buffer;
pnode newnode(int x = 1) {
	buffer.emplace_back(x);
	return &buffer.back();
}

pnode merge(pnode l, pnode r)
{
	pnode ret = newnode(1);
	ret->mul = l->mul *1ll* r->mul % mod;
	ret->l = l;
	ret->r = r;
	return ret;
}

pnode init(int l, int r)
{
	if(l == r) { return (newnode(1));}

	int mid = (l + r) >> 1;
	return merge(init(l, mid), init(mid + 1, r));
}

pnode update(int pos, int val, int l, int r, pnode nd)
{
	if(pos < l || pos > r) return nd;
	if(l == r) { return (newnode(val)); }

	int mid = (l + r) >> 1;
	return merge(update(pos, val, l, mid, nd->l), update(pos, val, mid + 1, r, nd->r));
}

int query(int qL, int qR, int l, int r, pnode nd)
{
	if(qL <= l && r <= qR) return nd->mul;
	if(qL > r || qR < l) return 1;

	int mid = (l + r) >> 1;
	return query(qL, qR, l, mid, nd->l) * 1ll * query(qL, qR, mid + 1, r, nd->r) % mod;
}
bool prime(int n) {
	for(int d = 2; d*d <= n; d++) if(n%d == 0) return 0;
	return 1;
}
vector<int> primes;
vector<RMQ<char>> z;
int n;
vector<int> a;
int bp(int a, int p) {
	int r = 1;
	while(p) {
		if(p&1) r = r*1ll*a%mod;
		a = a*1ll*a%mod, p>>=1;
	}
	return r;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int i = 2; i*i < (1<<18); i++) if(prime(i)) primes.push_back(i);
	cin >> n;
	a.resize(n);
	for(auto &i : a) cin >> i;
	for(int p = 0; p < primes.size(); p++) {
		vector<char> t(n);
		for(int i = 0; i < n; i++) {
			int c = 0;
			while(a[i]%primes[p] == 0) {
				a[i] /= primes[p];
				c++;
			}
			t[i] = c;
		}
		z.emplace_back(t);
	}
	vector<pnode> f;
	pnode root = 0;
	root = init(0, n);
	map<int, int> lst;
	for(int i = 0; i < n; i++) {
		if(a[i] > 1) { 
		if(lst.count(a[i])) {
			root = update(lst[a[i]], 1, 0, n, root);
		}
		lst[a[i]] = i;
		root = update(i, a[i], 0, n, root);
		}
		f.push_back(root);
	}
	int q, l, r, x = 0;
	for(cin >> q; q--;) {
		cin >> l >> r;
		l = (l+x)%n;
		r = (r+x)%n;
		if(l > r) swap(l, r);
		int cur = query(l, r, 0, n, f[r]);
		for(int i = 0; i < primes.size(); i++) {
			cur = cur * 1ll * bp(primes[i], z[i].query(l, r+1)) % mod;
		}
		cout << (x=cur) << '\n';
	}
}