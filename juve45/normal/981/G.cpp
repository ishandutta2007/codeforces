#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 200100;
const int MOD = 998244353;
int n, q;

set <pair<int, int> > seg[N];

long long st[4 * N], lazy[4 * N], inc[4 * N];

int val(int node, int l, int r) {
	return (lazy[node] * st[node] + inc[node] * (r - l + 1)) % MOD;
}

void push(int node, int l, int r) {
	st[node] = val(node, l, r);
	if((lazy[node] != 1 || inc[node]) && l != r) {

		lazy[2 * node] = (lazy[2 * node] * lazy[node]) % MOD;
		lazy[2 * node + 1] = (lazy[2 * node + 1] * lazy[node]) % MOD;
		inc[2 * node] = (inc[2 * node] * lazy[node] + inc[node]) % MOD;
		inc[2 * node + 1] = (inc[2 * node + 1] * lazy[node] + inc[node]) % MOD;

	}
	inc[node] = 0;
	lazy[node] = 1;
}

void upd(int node, int l, int r, int x, int y, int mul, int add) {
	push(node, l, r);

	if(x <= l && r <= y) {
		lazy[node] = (lazy[node] * mul) % MOD;
		inc[node] = (inc[node] * mul) % MOD;
		inc[node] = (inc[node] + add) % MOD;
		return;
	}

	int mid = (l + r) / 2;
	if(x <= mid) upd(2 * node, l, mid, x, y, mul, add);
	if(mid < y) upd(2 * node + 1, mid + 1, r, x, y, mul, add);

	st[node] = (val(2 * node, l, mid) + val(2 * node + 1, mid + 1, r)) % MOD;
}


int que(int node, int l, int r, int x, int y) {
	push(node, l, r);

	if(x <= l && r <= y)
		return st[node];

	int mid = (l + r) / 2, ret = 0;
	if(x <= mid) ret += que(2 * node, l, mid, x, y);
	if(mid < y) ret += que(2 * node + 1, mid + 1, r, x, y);
	return ret % MOD;
}

bool included(pair<int, int > a, pair <int, int> b) {
	if(b.st <= a.st && a.nd <= b.nd)
		return 1;	
	return 0;
}

bool intersect(pair<int, int > a, pair <int, int> b) {
	if(a.nd < b.st) return 0;
	if(b.nd < a.st) return 0;
	return 1;
}

void add(int l, int r) {
	// dbg("add", l, r);
	if(l > r) return;
	upd(1, 1, n, l, r, 1, 1);
}

void mul(int l, int r) {
	// dbg("mul", l, r);
	if(l > r) return;
	upd(1, 1, n, l, r, 2, 0);
}

void prel(int nr, int l, int r) {

	// dbg(nr, l, r);
	auto fi = seg[nr].lower_bound({l, 0});
	if(fi != seg[nr].begin())
		fi = prev(fi);
	auto la = seg[nr].lower_bound({r + 1, 0}); 

	int ll = l, rr = r;
	
	set <pair<int, int> > to_erase;

	int last = l;
	pair<int, int> ths = {l, r};
	for(auto it = fi; it != la; it++) {
		if(included(*it, ths)) {
			
			to_erase.insert(*it);
			
			add(last, it->st - 1);
			mul(it->st, it->nd);
			
			last = it->nd + 1;
		} else if(intersect(*it, ths)) {

			to_erase.insert(*it);
			ll = min(ll, it->st);
			rr = max(rr, it->nd);
			
			add(last, it->st - 1);
			mul(max(it->st, l), min(it->nd, r));
			
			last = it->nd + 1;
		} 
	}

	add(last, r);

	for(auto i : to_erase) seg[nr].erase(i);
	seg[nr].insert({ll, rr});
	// dbg(seg[nr]);
}



int main() {
	ios_base::sync_with_stdio(false);

	for(int i = 1; i < 4 * N; i++) lazy[i] = 1;

	cin >> n >> q;
	int l, r, x, op;
	
	for(int i = 1; i <= q; i++) {
		cin >> op;
		if(op == 1) {
			cin >> l >> r >> x;
			prel(x, l, r);
		} else {
			cin >> l >> r;
			cout << que(1, 1, n, l, r) << '\n';
		}
	}

}