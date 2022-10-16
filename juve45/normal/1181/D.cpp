#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <bits/stdc++.h>
#define st first
#define nd second

using namespace __gnu_pbds;
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
// template<class T> ostream& operator<<(ostream& out, ordered_set v) { return prnt(out, v); }


#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 500500;
long long n, m, q, a, f[N], ans[N];
vector <pair<long long, long long> > w, v;
ordered_set os;
set <long long> s;

int main() {
	ios_base::sync_with_stdio(false);	

	cin >> n >> m >> q;
	for(long long i = 1; i <= n; i++) {
		cin >> a;
		f[a]++;
	}

	for(long long i = 1; i <= m; i++)
		v.push_back({f[i], i}), s.insert(f[i]);

	sort(v.begin(), v.end());

	// dbg(v);
	for(long long i = 1; i <= q; i++) {
		cin >> a;
		w.push_back({a - n, i});
	}
	sort(w.begin(), w.end());

	long long curr;
	long long j = 0, sum = 0, ant = 0, jj = 0;
	// dbg(w);
	for(auto i : s) {
		
		long long sum2 = sum + os.size() * (i - ant);
		// dbg(sum2);

		while(jj < w.size() && w[jj].st <= sum2) {
			long long order = (long long)((w[jj].st - sum - 1) % (long long) os.size());
			// dbg(sum, w[jj].st, order);
			ans[w[jj].nd] = *os.find_by_order(order);
			jj++;
		}
		sum = sum2;
		while(j < v.size() && v[j].st == i)
			os.insert(v[j++].nd);
		
		ant = i;
	}
	// dbg_v(ans, q + 1);
	// dbg(sum);
	while(jj < w.size()) {
		long long order = (long long)((w[jj].st - sum - 1) % (long long) os.size());
		ans[w[jj].nd] = *os.find_by_order(order);
		jj++;
	}
	for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}