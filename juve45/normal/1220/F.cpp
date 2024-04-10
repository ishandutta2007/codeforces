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

const int N = 400100;
int n, l[N], r[N], p[N], v[N], pos[N], swp, d[N], pl[N], pr[N], lazy[4 * N], st[4 * N], fth[N];
int DBG;

void dfs(int pos, int lvl = 1) {
	d[pos] = lvl;
	if(pl[pos]) dfs(pl[pos], lvl + 1);
	if(pr[pos]) dfs(pr[pos], lvl + 1);
}

void push(int nod, int l, int r) {
	if(lazy[nod]) {
		st[nod] += lazy[nod];
		if(l != r)
			lazy[2 * nod + 1] +=	lazy[nod],
			lazy[2 * nod] += lazy[nod];
		lazy[nod] = 0;
	}
}

int val(int nod, int l, int r) {
	return st[nod] + lazy[nod];
}

void upd_interv(int nod, int l, int r, int x, int y, int vall) {
	assert(nod > 0 && nod < 4 * N);
	push(nod, l, r);
	// if(l == r) return void(st[nod] += vall);
	if(x <= l && r <= y) {
		lazy[nod] += vall;
		return;
	}
	assert(l != r);

	int mid = (l + r) / 2;
	if(x <= mid) upd_interv(2 * nod, l, mid, x, y, vall);
	if(y > mid) upd_interv(2 * nod + 1, mid + 1, r, x, y, vall);
	
	st[nod] = max(val(2 * nod, l, mid),  val(2 * nod + 1, mid + 1, r));
}

int que(int nod, int l, int r, int x, int y) {
	push(nod, l, r);

	// if(DBG) dbg(nod, l, r, st[nod], lazy[nod]);

	if(x <= l && r <= y)
		return val(nod, l, r);

	int mid = (l + r) / 2, ret = 0;

	if(x <= mid) ret = max(ret, que(2 * nod, l, mid, x, y));
	if(y > mid) ret = max(ret, que(2 * nod + 1, mid + 1, r, x, y));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++)  {
		cin >> p[i];
	}

	for(int i = n + 1; i <= 2 * n; i++)  {
		p[i] = p[i - n];
		if(p[i] == 1) swp = i - n;
	}

	for(int i = 1; i <= n; i++)
		v[i] = p[i + swp];
	for(int i = n + 1; i <= 2 * n; i++)
		v[i] = v[i - n];
	for(int i = 1; i <= 2 * n; i++) 
		p[i] = v[i];
	for(int i = 1; i <= n; i++)
		pos[p[i]] = i;

	// dbg_v(p, 2 *a n + 1);
	
	stack <int> st;

	for(int i = 1; i <= 2 * n; i++) {
		while(!st.empty() && p[st.top()] >= p[i]) {
			if(p[st.top()] != p[i]) r[st.top()] = i;
			st.pop();
		}

		if(!st.empty())
			l[i] = st.top();

		st.push(i);
	}

	for(int i = 1; i <= n; i++) {
		if(r[i]) {
			if(!pl[r[i]])
				pl[r[i]] = i;
			else if(p[pl[r[i]]] > p[i])
				pl[r[i]] = i;
		}

		if(l[i]) {
			if(!pr[l[i]])
				pr[l[i]] = i;
			else if(p[pr[l[i]]] > p[i])
				pr[l[i]] = i;
		}
	}

	for(int i = 1; i <= n; i++) {
		if(pl[i]) fth[pl[i]] = i;
		if(pr[i]) fth[pr[i]] = i;
	}

	dfs(pos[1]);
	// dbg_v(fth, 2 * n + 1);
	// dbg_v(pl, 2 * n + 1);
	// dbg_v(pr, 2 * n + 1);
	// dbg_v(d, 2 * n + 1);

	for(int i = 1; i <= n; i++)
		upd_interv(1, 1, 2 * n, i, i, d[i]);

	int ans = n, rot = 0;
	// dbg(que(1, 1, 2 * n, 1, n));

	while(!st.empty())
		st.pop();

	st.push(n);

	// dbg(que(1, 1, 2 * n, 3, 3));
	// DBG = 1;
	// dbg(::st[17], lazy[17]);
	// dbg(que(1, 1, 2 * n, 2, 2));
	for(int i = 1; i < n; i++) {
		// dbg("============ ", i, que(1, 1, 2 * n, i, i + n - 1));
		int tmp = que(1, 1, 2 * n, i, i + n - 1);
		if(ans > tmp) {
			ans = tmp;
			rot = i - 1;
		}

		while(p[st.top()] > p[n + i]) 
			st.pop();

		upd_interv(1, 1, 2 * n, i, fth[i] - 1, -1);
		// dbg(::st[17], lazy[17]);
		// dbg(i, fth[i] - 1, -1);
		// dbg(fth[i], st.top(), st.size());
		upd_interv(1, 1, 2 * n, n + i, n + i, st.size());
		// dbg(n + i, n + i, st.size());

		fth[pr[i]] = fth[i];
		fth[n + i] = st.top();
		pl[n + i] = pr[st.top()];
		pr[st.top()] = n + i;

		upd_interv(1, 1, 2 * n, st.top() + 1, n + i, 1);
		// dbg(st.top() + 1, n + i, 1);
		// dbg(que(1, 1, 2 * n, 2, 2));
		// return 0;
		st.push(n + i);
	}

	int tmp = que(1, 1, 2 * n, n, n + n - 1);
	if(ans > tmp) {
		ans = tmp;
		rot = n - 1;
	}

	cout << ans << ' ' << (rot + swp) % n<< '\n';
}