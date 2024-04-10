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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 500100;
long long n, st[8 * N], lazy[8 * N], x[2 * N], y[2 * N], c[2 * N], stval[2 * N], value[2 * N], minpos[8 * N];
map <long long, long long> mp;
vector <pair<pair<long long, long long>, long long> > seg;

long long val(long long node) {
	return st[node] + lazy[node];
}

void push(long long node, long long l, long long r) {
	if(lazy[node]) {
		st[node] += lazy[node];
		if(l != r)
			lazy[2 * node] += lazy[node],
			lazy[2 * node + 1] += lazy[node];
		lazy[node] = 0;
	}
}

void upd(long long node, long long l, long long r, long long x, long long y, long long vall) {
	push(node, l, r);

	if(x <= l && r <= y)
		return void(lazy[node] += vall);

	long long mid = (l + r) / 2;
	if(x <= mid) upd(2 * node, l, mid, x, y, vall);
	if(mid < y) upd(2 * node + 1, mid + 1, r, x, y, vall);

	st[node] = max(val(2 * node), val(2 * node + 1));
	if(val(2 * node) > val(2 * node + 1))
		minpos[node] = minpos[2 * node];
	else 
		minpos[node] = minpos[2 * node + 1];
}


pair<long long, long long> que(long long node, long long l, long long r, long long x, long long y) {
	push(node, l, r);

	if(x <= l && r <= y) return {val(node), minpos[node]};
	
	long long mid = (l + r) / 2;
	pair<long long, long long> ansl = {-1e17, -1}, ansr = {-1e17, -1};
	if(x <= mid) ansl = que(2 * node, l, mid, x ,y);
	if(mid < y) ansr = que(2 * node + 1, mid + 1, r, x, y);
	
	return max(ansl, ansr);
}

void build(int node, int l, int r) {
	if(l == r) return void(minpos[node] = l);
	int mid = (l + r) / 2;
	build(2 * node, l, mid);
	build(2 * node + 1, mid + 1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	set <long long> val;

	cin >> n;
	for(long long i = 1; i <= n; i++) {
		cin >> x[i] >> y[i] >> c[i];
		if(x[i] > y[i]) swap(x[i], y[i]);
		val.insert(x[i]);
		val.insert(y[i]);
	}
	build(1, 1, 2 * n + 1);

	long long k = 1;
	for(auto i : val) {
		mp[i] = ++k;
		value[k] = i;
	}

	// memset(val, 0x3f, sizeof val);
	for(long long i = 1; i <= 2 * n + 1; i++)
		stval[i] = -1e18;
	for(long long i = 1; i <= n; i++)
		stval[mp[x[i]]] = x[i];

	for(long long i = 1; i <= 2 * n + 1; i++) {
		// dbg(i, stval[i]);
		upd(1, 1, 2 * n + 1, i, i, stval[i]);
	}

	// dbg(que(1, 1, 2 * n + 1, 6, 8));

	for(long long i = 1; i <= n; i++) {
		x[i] = mp[x[i]];
		y[i] = mp[y[i]];
		seg.push_back({{y[i], x[i]}, c[i]});
	}

	sort(seg.begin(), seg.end());

	// dbg(seg);
	long long j = 0;
	pair<long long, pair<long long, long long> > ans = {0, {2e9, 2e9}};

	for(auto i : val) {
		long long xx = mp[i];
		// dbg(i, xx);
		while(j < seg.size() && seg[j].st.st <= xx)  {
			upd(1, 1, 2 * n + 1, 1, seg[j].st.nd, seg[j].nd); 
			j++;
		}
		// dbg(j);
		auto tmp = que(1, 1, 2 * n + 1, 1, xx);
		tmp.st -= i;
		long long r = i;
		if(tmp.st > ans.st)
			ans = {tmp.st, {value[tmp.nd], r}};
	}
	cout << ans.st << '\n';
	cout << ans.nd.st << ' ' << ans.nd.st << ' ';
	cout << ans.nd.nd << ' ' << ans.nd.nd << ' ';
}