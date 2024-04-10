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

const int N = 300100;
vector <int> pos[N];
int st[4 * N], b[N], a[N], t;

void upd(int node, int l, int r, int pos, int val) {
	if(l == r) {
		st[node] = val;
		return;
	}
	int mid = (l + r) / 2;
	if(pos <= mid) upd(2 * node, l, mid, pos, val);
	else upd(2 * node + 1, mid + 1, r, pos, val);
	st[node] = min(st[2 * node], st[2 * node + 1]);
}

int que(int node, int l, int r, int x, int y) {
	if(x <= l && r <= y) return st[node];

	int mid = (l + r) / 2, ans1 = 1e9, ans2 = 1e9;
	if(x <= mid) ans1 = que(2 * node, l, mid, x, y);
	if(y > mid) ans2 = que(2 * node + 1, mid + 1, r, x, y);
	return min(ans1, ans2);
}

string solve() {
	int n, m, ok = 1;
	cin >> n;

	for(int i = 1; i <= n; i++) pos[i].clear();
	memset(st, 0, 4 * n);
	// dbg(n);
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		upd(1, 1, n, i, a[i]);
		pos[a[i]].push_back(i);
	}
	for(int i = 1; i <= n; i++) 
		reverse(pos[i].begin(), pos[i].end());
	
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
		if(pos[b[i]].empty()) {ok = 0;continue;}
		int min_pos = pos[b[i]].back();
		// dbg(b[i], min_pos, ok);
		pos[b[i]].pop_back();

		if(que(1, 1, n, 1, min_pos) < b[i]) ok = 0;
		// dbg(ok);
		upd(1, 1, n, min_pos, 1e9);
		// dbg_ok;
	}
	if(!ok) return "NO";
	return "YES";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) cout << solve() << '\n';
}