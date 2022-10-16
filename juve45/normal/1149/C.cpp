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
int n, d[4 * N], ans[4 * N], mx[4 * N][4], mn[4 * N], m, l, r;
string s;

int upd_node(int node) {

	d[node] = d[2 * node] + d[2 * node + 1];

	mn[node] = min(mn[2 * node], d[2 * node] + mn[2 * node + 1]);
	mx[node][0] = max(mx[2 * node][0], d[2 * node] + mx[2 * node + 1][0]);

	mx[node][1] = max({
		mx[2 * node][1], 
		mx[2 * node + 1][1] - d[2 * node], 
		mx[2 * node + 1][0] + d[2 * node] - 2 * mn[2 * node]
		});

	mx[node][2] = max({
		mx[2 * node][2], 
		mx[2 * node + 1][2] - d[2 * node], 
		mx[2 * node][0] - 2 * (mn[2 * node + 1] + d[2 * node])
		});

	ans[node] = max({
		ans[2 * node], ans[2 * node + 1], 
		mx[2 * node][0] + mx[2 * node + 1][1] - d[2 * node], 
		mx[2 * node][2] + mx[2 * node + 1][0] + d[2 * node]
		});
}

void upd(int node, int l, int r, int pos, int val) {
	if(l == r) {
		d[node] = val;
		mn[node] = mx[node][0] = mx[node][1] = mx[node][2] = 0;
		return;
	}
	int mid = (l + r) / 2;
	if(pos <= mid) upd(2 * node, l, mid, pos, val);
	else upd(2 * node + 1, mid + 1, r, pos, val);

	upd_node(node);
	// dbg(node, l, r, d[node]);
	// dbg(ans[node], mx[node][0], mn[node]);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		upd(1, 1, 2 * n, i + 1, (s[i] == '(' ? 1 : -1));//, dbg_ok;
	// dbg_ok;
	
	cout << ans[1] << '\n';

	for(int i = 1; i <= m; i++) {
		cin >> l >> r;
		l--, r--;
		if(s[l] != s[r])  {
			swap(s[l], s[r]);
			upd(1, 1, 2 * n, l + 1, (s[l] == '(' ? 1 : -1));
			upd(1, 1, 2 * n, r + 1, (s[r] == '(' ? 1 : -1));		
		}
		cout << ans[1] << '\n';
	}
}