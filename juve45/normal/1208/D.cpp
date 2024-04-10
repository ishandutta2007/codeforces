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

const long long N = 200100;
long long n, st[4 * N + 123], mn[4 * N + 123], lazy[4 * N + 123], s[N], p[N];

long long vall(long long nod, long long l, long long r) {
	return mn[nod] + lazy[nod];
}

void push(long long nod, long long l, long long r) {
	if(lazy[nod]) {
		mn[nod] += lazy[nod];
		if(l < r) {
			lazy[2 * nod] += lazy[nod];
			lazy[2 * nod + 1] += lazy[nod];
		}
		lazy[nod] = 0;
	}
}

void upd(long long nod, long long l, long long r, long long x, long long y, long long val) {
	// dbg(nod, l, r, x, y, val);
	if(st[nod] == 0) st[nod] = r;
	push(nod, l, r);

	if(l == r) {
		st[nod] = r;
		mn[nod] += val;
		return ;
	}

	long long mid = (l + r) / 2;

	if(x <= l && r <= y)
		lazy[nod] += val;
	else{
		if(x <= mid) upd(2 * nod, l, mid, x, y, val);
		if(y > mid) upd(2 * nod + 1, mid + 1, r, x, y, val);
	}
	// dbg(vall(2 * nod, l, mid), vall(2 * nod + 1, mid + 1, r));
	if(vall(2 * nod, l, mid) < vall(2 * nod + 1, mid + 1, r))
		st[nod] = st[2 * nod];
	else 
		st[nod] = st[2 * nod + 1];
	mn[nod] = min(vall(2 * nod, l, mid), vall(2 * nod + 1, mid + 1, r));
	// dbg(nod, st[nod], st[2 * nod], st[2 * nod + 1]);
}

pair<long long, long long> que(long long nod, long long l, long long r, long long x, long long y) {
	push(nod, l, r);

	if(x <= l && r <= y)
		return {mn[nod], st[nod]};

	long long mid = (l + r) / 2, ans = 0;
	
	pair<long long, long long> ans1 = {1e15, -1}, ans2 = {1e15, -1};

	if(x <= mid) ans1 = que(2 * nod, l, mid, x, y);
	if(y > mid) ans2 = que(2 * nod + 1, mid + 1, r, x, y);
	
	if(ans1.st >= ans2.st)
		return ans2;
	return ans1;
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	// memset(mn, 0x3f, sizeof mn);
	for(long long i = 1; i <= n; i++)  {
		cin >> s[i];
		upd(1, 1, n, i, i, s[i]);
	}

	for(long long i = 1; i <= n; i++) {
		auto ppos = que(1, 1, n, 1, n);
		long long pos = ppos.nd;
		// dbg(i, ppos);
		assert(ppos.st == 0);
	
		p[pos] = i;
		upd(1, 1, n, pos + 1, n, -i);
		upd(1, 1, n, pos, pos, 1e16);
	}
	for(long long i = 1; i <= n; i++) cout << p[i] << ' ';
}