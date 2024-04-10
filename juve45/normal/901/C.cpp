#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_p(x) cerr<<#x": "<<x.first<<","<<x.second<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<(x)[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

#define DMAX 300100 
#define NMAX 
#define MMAX 

#define INF 1000000009

using namespace std;

long long n, k, x, a[DMAX], s[DMAX], st_min[4 * DMAX], st_max[4 * DMAX], m, q, n1, n2, use[DMAX], nrc = 1, aib[DMAX], h[DMAX];
long long st_sum[4 * DMAX], ans[DMAX];
vector <long long> v[DMAX];
priority_queue<pair<long long, long long> > pq;

struct lol {
	long long l, r, i;
} b[DMAX];

template<class T>
ostream& operator<<(ostream& out, vector<T> v)
{
	out << v.size() << '\n';
	for(auto e : v) out << e << ' ';
	return out;
}

void upd_min(long long node, long long l, long long r, long long pos, long long val) {
	if(l == r)
		return void(st_min[node] = val);
	if(pos <= (l + r) / 2) upd_min(2 * node, l, (l + r) / 2, pos, val);
	else upd_min(2 * node + 1, (l + r) / 2 + 1, r, pos, val);
	st_min[node] = min(st_min[2 * node], st_min[2 * node + 1]);
}

void upd_max(long long node, long long l, long long r, long long pos, long long val) {
	if(l == r)
		return void(st_max[node] = val);
	if(pos <= (l + r) / 2) upd_max(2 * node, l, (l + r) / 2, pos, val);
	else upd_max(2 * node + 1, (l + r) / 2 + 1, r, pos, val);
	st_max[node] = max(st_max[2 * node], st_max[2 * node + 1]);
}

void upd_sum(long long node, long long l, long long r, long long pos, long long val) {
	if(l == r)
		return void(st_sum[node] = val);
	if(pos <= (l + r) / 2) upd_sum(2 * node, l, (l + r) / 2, pos, val);
	else upd_sum(2 * node + 1, (l + r) / 2 + 1, r, pos, val);
	st_sum[node] = st_sum[2 * node] + st_sum[2 * node + 1];
}

long long get_sum(long long node, long long l, long long r, long long x, long long y) {
	if(x <= l && r <= y) return st_sum[node];
	long long ansl = 0, ansr = 0;
	if(x <= (l + r) / 2) ansl = get_sum(2 * node, l, (l + r) / 2, x, y);
	if(y >= (l + r) / 2 + 1) ansr = get_sum(2 * node + 1, (l + r) / 2 + 1, r, x, y);
	return ansl + ansr;
}

long long get_min(long long node, long long l, long long r, long long x, long long y) {
	if(x <= l && r <= y) return st_min[node];
	long long ansl = INF, ansr = INF;
	if(x <= (l + r) / 2) ansl = get_min(2 * node, l, (l + r) / 2, x, y);
	if(y >= (l + r) / 2 + 1) ansr = get_min(2 * node + 1, (l + r) / 2 + 1, r, x, y);
	return min(ansl, ansr);
}

long long get_max(long long node, long long l, long long r, long long x, long long y) {
	if(x <= l && r <= y) return st_max[node];
	long long ansl = 0, ansr = 0;
	if(x <= (l + r) / 2) ansl = get_max(2 * node, l, (l + r) / 2, x, y);
	if(y >= (l + r) / 2 + 1) ansr = get_max(2 * node + 1, (l + r) / 2 + 1, r, x, y);
	return max(ansl, ansr);
}


long long lsb(long long k) {
	return ((k ^ (k - 1)) & k);
}

void add(long long pos) {
	for(;pos < DMAX; pos += lsb(pos))
		aib[pos]++;
}

long long cnt(long long pos) {
	long long ans = 0;
	for(;pos > 0; pos -= lsb(pos))
		ans += aib[pos];
	return ans;
}

void dfs(long long k, long long t, long long d) {
	upd_min(1, 1, n, d, k);
	upd_max(1, 1, n, d, k);
	use[k] = nrc;
	h[k] = d;
	for(auto i : v[k])
		if(!use[i])
			dfs(i, k, d + 1);
		else if(use[i] == use[k] && i != t && h[i] < h[k]) {
			long long mn = get_min(1, 1, n, h[i], h[k]);
			long long mx = get_max(1, 1, n, h[i], h[k]) - 1;
			a[mn] = min(a[mn], mx);
		}
}

bool cmp(lol &a, lol &b) {
	return a.r < b.r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(long long i = 1; i <= 4 * n; i++) 
		st_min[i] = n + 1, st_max[i] = 0;
	
	for(long long i = 1; i <= n; i++) 
		a[i] = n;

	for(long long i = 1; i <= m; i++) {
		cin >> n1 >> n2;
		v[n2].push_back(n1);
		v[n1].push_back(n2);
	}
	// dbg_ok;
	for(long long i = 1; i <= n; i++)
		if(!use[i])
			dfs(i, -1, 1), nrc++;

	// dbg_v(a + 1, n);

	for(long long i = 1; i <= 4 * n; i++) 
		st_min[i] = n + 1, st_max[i] = 0;

	for(long long i = 1; i <= n; i++) 
		upd_min(1, 1, n, i, a[i]);

	// dbg_v(st_min, 4 * n);
	// dbg(get_min(1, 1, n, 4, 6));
	for(long long i = 1; i <= n; i++)
		s[i] = get_min(1, 1, n, i, a[i]);
	
	for(long long i = 1; i <= n; i++) {
		pq.push({-s[i], i});
	}

	// dbg_v(s + 1, n);

	cin >> q;
	for(long long i = 1; i <= q; i++)
		cin >> b[i].l >> b[i].r, b[i].i = i;

	sort(b + 1, b + q + 1, cmp);
	
	for(long long i = 1; i <= q; i++) {
		//inserez astea care au s[i] <= b[i].r!!!
		while(!pq.empty() && (-pq.top().st) <= b[i].r) {
			auto p = pq.top();
			pq.pop();
			upd_sum(1, 1, n, p.nd, -p.st);
			add(p.nd);
			// dbg(i);
			// dbg_v(aib, 20);
		}
		long long sum = get_sum(1, 1, n, b[i].l, b[i].r);
		// dbg(sum);
		long long ind = b[i].r * (b[i].r + 1) / 2 - b[i].l * (b[i].l - 1) / 2;
		// dbg(ind);
		long long anx = (b[i].r - b[i].l + 1 - cnt(b[i].r) + cnt(b[i].l - 1)) * b[i].r + sum - ind; 
		// dbg(b[i].r - b[i].l + 1 - cnt(b[i].r) + cnt(b[i].l - 1));
		ans[b[i].i] = anx + b[i].r - b[i].l + 1;
	}

	for(long long i = 1; i <= q; i++)
		cout << ans[i] << '\n';
}