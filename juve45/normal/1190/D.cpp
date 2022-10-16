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
long long n, x, y, ans, has[4 * N];
vector <long long> coords, g[4 * N];
vector <pair<long long, long long> > v;
set <long long> ys;
map <long long, long long> m;
 
long long aib[4 * N + 50];

long long lsb(long long k) {return k & (-k); }

void put(long long pos) {
	pos++;
	for(; pos <= 4 * N + 24; pos += lsb(pos))
		aib[pos]++;
}

long long que(long long pos) {
	pos++;
	if(pos == 0) while(1);
	long long ret = 0;
	for(; pos; pos -= lsb(pos))
		ret += aib[pos];
	return ret;
}

long long cnt(long long a, long long b) {
	a++;
	b--;
	if(a > b) return 0;
	return que(b) - que(a - 1);
}

long long gg(long long k) {
	return k * (k + 1) / 2;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(long long i= 1; i <= n; i++) {
		cin >> x >> y;
		y = -y;
		v.push_back({y, x});
		coords.push_back(x);
		coords.push_back(y);
	}

	coords.push_back(-1e9 - 100);
	sort(coords.begin(), coords.end());
	dbg(coords.size());
	for(long long i = 0; i < coords.size(); i++)
		m[coords[i]] = i;
	// dbg(coords);

	sort(v.begin(), v.end());
	for(auto &i : v) {
		i.st = m[i.st];
		i.nd = m[i.nd];
		assert(i.nd <= 2 * N + 10);
		assert(i.st <= 2 * N + 10);
		g[i.st].push_back(i.nd);
		ys.insert(i.st);
	}

	for(auto i : ys) {
		
		for(auto j : g[i]) 
			if(!has[j]) {
				has[j] = 1;
				put(j);
			}
	
		long long tmp = que(4 * N + 3);
		tmp = tmp * (tmp + 1) / 2;
		// dbg(g[i]);
		g[i].push_back(4 * N + 3);
		// dbg(tmp);

		for(long long j = 0; j < g[i].size(); j++) {
			if(j == 0)  {
				// dbg(cnt(0, g[i][0]));
				tmp -= gg(cnt(0, g[i][0]));
			} else {
				// dbg(cnt(g[i][j - 1], g[i][j]));
				tmp -= gg(cnt(g[i][j - 1], g[i][j]));
			}
		}
		ans += tmp;
		// dbg(i, tmp, ans);
		assert(tmp >= 0);
		assert(ans >= 0);
	}
	cout << ans << '\n';
}