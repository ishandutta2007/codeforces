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

const int N = 100100;
int n, m, l, r, k;

string s;
vector <int> range[3];


struct SegTree{
	int tree[4 * N], sum[4 * N];
	int n;

	void setN(int _n) {n = _n;}

	int value(int node, int l, int r) {
		if(tree[node])
			return tree[node] * (r - l + 1);
		return sum[node];
	}

	void push(int node, int l, int r) {
		if(tree[node] && l != r) {
			tree[2 * node] = tree[2 * node + 1] = tree[node];
			sum[node] = tree[node] * (r - l + 1);
			tree[node] = 0;
		}
	}

	void _upd_range(int node, int l, int r, int x, int y, int val) {
		push(node, l, r);
		if(l == r) return void(tree[node] = val);
		
		if(x <= l && r <= y) return void(tree[node] = val);
		
		int mid = (l + r) / 2;
		if(x <= mid) _upd_range(2 * node, l, mid, x, y, val);
		if(y > mid) _upd_range(2 * node + 1, mid + 1, r, x, y, val);

		if(tree[2 * node] == tree[2 * node + 1])
			tree[node] = tree[2 * node];
		else tree[node] = 0;

		sum[node] = value(2 * node, l, mid) + value(2 * node + 1, mid + 1, r);
	}

	int _que(int node, int l, int r, int x, int y) {
		push(node, l, r);
		
		if(x <= l && r <= y)
			return value(node, l, r);

		int mid = (l + r) / 2, ret = 0;
		if(x <= mid) ret += _que(2 * node, l, mid, x, y);
		if(y > mid) ret += _que(2 * node + 1, mid + 1, r, x, y);
		return ret;
	}

	void upd_range(int l, int r, int val) {
		_upd_range(1, 1, n, l, r, val);
	}

	int que(int l, int r) {
		return _que(1, 1, n, l, r);
	}
};
SegTree st[27];

void solve(int l, int r, int k) {

	int f[26];
	memset(f, 0, sizeof f);
	for(int i = 0; i < 26; i++) {
		f[i] = st[i].que(l, r) - (r - l + 1);
		st[i].upd_range(l, r, 1);
	}
	// dbg_v(f, 26);
	int last_pos = l;
	for(auto i : range[k]) {
		if(f[i] == 0) continue;
		st[i].upd_range(last_pos, last_pos + f[i] - 1, 2);
		last_pos += f[i];
	}
}


int main() {
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 26; i++)
		range[0].push_back(i),
		range[1].push_back(i);
	reverse(range[0].begin(), range[0].end());

	cin >> n >> m >> s;
	for(int i = 0; i < 26; i++) {
		st[i].setN(n);
		st[i].upd_range(1, n, 1);
	}

	s = "$" + s;

	for(int i = 1; i <= n; i++)
		st[s[i] - 'a'].upd_range(i, i, 2);

	for(int i = 1; i <= m; i++) {
		cin >> l >> r >> k;
		solve(l, r, k);
		// dbg(st[3].que(1, 1));
	}

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 26; j++)
			if(st[j].que(i, i) == 2) {
				cout << char(j + 'a');
				// break;
			}
}