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

#define dbg(...) //cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 100100;
long long n, aib[N], a[N], l[N], r[N], k, ans, inv;
map <long long, long long> mp;

long long lsb(long long r) { return r & (-r);}

void add(long long pos, long long val) {
	for(; pos < N; pos += lsb(pos))
		aib[pos] += val;
}

long long que(long long pos) {
	long long ret = 0;
	for(; pos ; pos -= lsb(pos)) 
		ret += aib[pos];
	return ret;
}

long long cb(long long x, long long y, long long lim, long long i) {
	while(x != y) {
		long long mid = (x + y) / 2;
		if(l[mid - 1] - l[i] + r[mid - 1] - r[i] >= lim)
			y = mid;
		else 
			x = mid + 1;
	}
	return y;
}

long long cnt(int x, int y) {
	return r[y - 1] - r[x] + l[y - 1] - l[x] - inv;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	vector <long long> v;
	for(long long i = 1; i <= n; i++) {
		cin >> a[i];
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	for(long long i = 0; i < v.size(); i++) {
		mp[v[i]] = i + 1;
	}

	for(long long i = 1; i <=n ; i++ ) 
		a[i] = mp[a[i]];

	for(long long i = 1; i <= n; i++) {
		l[i] = que(n) - que(a[i]);
		ans += l[i];
		add(a[i], 1);
	}
	
	memset(aib, 0, sizeof aib);

	for(long long i = n; i > 0; i--) {
		r[i] = que(a[i] - 1);
		ans += r[i];
		add(a[i], 1);
	}

	// dbg_v(r, n + 1);
	// dbg_v(l, n + 1);
	for(long long i = 1; i <= n; i++)
		l[i] += l[i - 1],
		r[i] += r[i - 1];

	// l[n + 1] = r[n + 1] = ans;
	long long tot = ans;
	long long lim = ans - 2 * k;
	
	assert(lim % 2 == 0);

	ans = 0;

	// dbg(lim);
	memset(aib, 0, sizeof aib);


	int j = 2;
	// add(a[1], 1);
	for(long long i = 1; i < n; i++) {
		if(i > 1 && i < j) {
			add(a[i], -1);
			inv -= que(a[i] - 1);
		}

		dbg(i, j, cnt(i, j));
		while(j <= i || j <= n && 2 * cnt(i, j) < lim) {
			if(j > i) {
				dbg(a[j]);
				add(a[j], 1);
				inv += que(n + 1) - que(a[j]);
			}
			j++;
			dbg(i, j, cnt(i, j), inv);
		}
		dbg(i, j, cnt(i, j));
		ans += (n + 1 - j);
	}
	cout << ans << '\n';
}