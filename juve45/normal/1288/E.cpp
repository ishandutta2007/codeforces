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

const int N = 300100;
int n, m, a[2 * N], mn[N], mx[N], seen[N];

int aib[2 * N];

int lsb(int k) {return k & (-k);}

void upd(int pos, int val) {
	for(; pos < 2 * N; pos += lsb(pos))
	aib[pos] += val;
}

int que(int pos) {
	int tmp = 0;
	for(; pos; pos -= lsb(pos))
		tmp += aib[pos];
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 1; i <= n; i++) a[i] = n - i + 1, mn[i] = i, mx[i] = i;

	for(int i = 1; i <= m; i++) cin >> a[n + i], mn[a[n + i]] = 1;

	// reverse(a + 1, a + n + m + 1);
	// dbg_v(a, n + m + 1);

	for(int i = 1; i <= n + m; i++) {
		// dbg(i, a[i]);
		if(!seen[a[i]]) {
			upd(i, 1);
			seen[a[i]] = i;
		} else {
			mx[a[i]] = max(mx[a[i]], que(2 * N - 1) - que(seen[a[i]]) + 1);
			upd(seen[a[i]], -1);
			upd(i, 1);
			// dbg(que(2 * N - 1) - que(seen[a[i]]));
			seen[a[i]] = i;
		}
	}

	for(int i = 1; i <= n; i++) 
		mx[a[i]] = max(mx[a[i]], que(2 * N - 1) - que(seen[a[i]]) + 1);
	
	for(int i = 1; i <= n; i++) 
		cout << mn[i] << ' ' << mx[i] << '\n';


}