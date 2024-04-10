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
int n, ans, dpl[N], dpr[N], cntl[N], cntr[N], a[N], need[N], res[N];
map <int, int> m[N];
vector <int> v[N];

void put(int val, int lg, int cnt) {
	m[lg][val] += cnt;
}

pair<int, int> cb(int val) {
	int l = 0, r = n;
	while(l != r) {
		// dbg(l, r);
		int mid = (l + r + 1) / 2;
		if(!m[mid].empty() && m[mid].begin()->st < val) 
			l = mid;
		else r = mid - 1;
	}
	// dbg(l);
	if(m[l].begin()->nd > 1) return {l + 1, 2};
	if(m[l].size() == 1) return {l + 1, 1};
	if(next(m[l].begin())->st < val) return {l + 1, 2};
	return {l + 1, 1};
}

void solve(int * a, int * dp, int * cnt) {
	for(int i = 1; i <= n; i++)
		m[i].clear();
	m[0][0] = 1;

	for(int i = 1; i <= n; i++ ) {
		// dbg(i);
		pair<int, int> p = cb(a[i]);
		// dbg(p);
		put(a[i], p.st, p.nd);
		dp[i] = p.st;
		cnt[i] = p.nd;
		ans = max(ans, p.st);
	}

}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];

	solve(a, dpl, cntl);
	reverse(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) a[i] = 1e5 + 1 - a[i];
	solve(a, dpr, cntr);
	reverse(cntr + 1, cntr + n + 1);
	reverse(dpr + 1, dpr + n + 1);

	// dbg_v(dpl, n + 1);
	// dbg_v(dpr, n + 1);

	need[0] = 1e9;

	for(int i = 1; i <= n; i++) a[i] = 1e5 + 1 - a[i];
	reverse(a + 1, a + n + 1);
	// dbg_v(a, n + 1);
	for(int i = n; i > 0; i--) {
		if(dpl[i] + dpr[i] < ans + 1) continue;

		// dbg(i, dpr[i], need[dpr[i] - 1], a[i]);
		if(need[dpr[i] - 1] > a[i])
			v[dpl[i]].push_back(i);

		need[dpr[i]] = max(need[dpr[i]], a[i]);
		// dbg(dpr[i], need[dpr[i]]);
	}

	for(int i = 1; i <= ans; i++)
		if(v[i].size() == 1)
			res[v[i][0]] = 1;

	for(int i = 1; i <= n; i++) {
		if(dpl[i] + dpr[i] < ans + 1) cout << '1';
		else if(res[i] == 1) cout << '3';
		else cout << '2';
	}

}