#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

using namespace std;

const int N = 35010;
int n, k, prv[N], last[N], a[N], lazy[55][4 * N], st[55][4 * N], dp[55][N];

template<class T>
ostream& operator<<(ostream& out, vector<T> v) {
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

template<class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> p) {
	return out << '(' << p.st << ' ' << p.nd << ')';  
}

void push(int w, int node, int l, int r) {
	if(lazy[w][node]) {
		st[w][node] += lazy[w][node];
		if(l < r) {
			lazy[w][2 * node] += lazy[w][node];
			lazy[w][2 * node + 1] += lazy[w][node];
		}
		lazy[w][node] = 0;
	}
}

void add(int w, int node, int l, int r, int x, int y, int val) {
	push(w, node, l, r);

	if(x <= l && r <= y) {
		lazy[w][node] += val;
		return;
	}

	if(r < x || l > y)
		return;

	int mid = (l + r) / 2;
	add(w, 2 * node, l, mid, x, y, val);
	add(w, 2 * node + 1, mid + 1, r, x, y, val);
	st[w][node] = max(st[w][2 * node] + lazy[w][2 * node], st[w][2 * node + 1] + lazy[w][2 * node + 1]);
}	

int que(int w, int node, int l, int r, int x, int y) {
	push(w, node, l, r);

	if(x <= l && r <= y)
		return st[w][node];

	if(r < x || l > y)
		return 0;
	int mid = (l + r) / 2;
	int ansl = que(w, 2 * node, l, mid, x, y);
	int ansr = que(w, 2 * node + 1, mid + 1, r, x, y);
	return max(ansl, ansr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		prv[i] = last[a[i]];
		last[a[i]] = i;
	}

	// in seg tree tin de la poz 
	for(int i = 1; i <= n; i++) {
		//dp[j][i]
		for(int j = 1; j <= k; j++) {
			add(j, 1, 1, n, i, i, dp[j - 1][i - 1]);
			add(j, 1, 1, n, prv[i] + 1, i, 1);
			// dbg(i);
			// dbg(prv[i]);
			// dbg(que(j, 1, 1, n, 1, i));
			// dbg(que(j, 1, 1, n, 1, i - 1));
			dp[j][i] = que(j, 1, 1, n, 1, i);
		}
	}
	cout << dp[k][n] << '\n';
}