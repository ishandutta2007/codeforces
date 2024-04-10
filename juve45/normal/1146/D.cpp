#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) {for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " | " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;  // ordered_set <long long> s; // order_of_key(value)

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second


const long long N = 800100;
long long n, k, m, a, b, f[N], lim, use[N], ans;
set <long long> waiting;
vector <long long> v[N];

void dfs(long long node) {
	f[lim]++;
	use[node] = 1;

	for(auto i : v[node])
		if(i <= lim && !use[i])
			dfs(i);
		else if(i > lim) 
			waiting.insert(i);
}

long long sum(long long l, long long r, long long g) {
	long long R = r / g;
	R *= g;
	long long nr = (R - l) / g;
	// dbg(l, r, g, R, nr);
	// dbg(nr);
	// long long ans = 0;
	long long ans = g * ((nr + 1) * nr / 2 + nr * (l / g)) ;
	// dbg(ans);
	for(long long i = R; i <= r; i++)
		ans += i / g + 1;
	// dbg(ans);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> m >> a >> b;
	// long long g = __gcd(a, b);
	// dbg(a);
	// dbg(b);
	// a /= g;
	// b /= g;
	// m /= g;

	// pt orice raspuns > (a + b) rezultatul este f(a + b) + (m - a - b);
	long long X = 2 * (a + b);

	for(long long i = 0; i <= X + b; i++)
		v[i].push_back(i + a);

	for(long long i = b; i <= X + a + b; i++)
		v[i].push_back(i - b);

	f[0] = 1;
	use[0] = 1;
	waiting.insert(a);

	for(lim = 1; lim <= X + a + b; lim++) {
		f[lim] = f[lim - 1];

		// dbg(waiting);

		if(*waiting.begin() == lim) {
			waiting.erase(waiting.begin());
			dfs(lim);
		}
	}

	for(long long i = 0; i <= min(m, X + a + b - 1); i++)
		ans += f[i];

	// dbg_v(f, X + X);

	// dbg(sum(4, 10, 1));
	// return 0;

	// dbg(ans);
	// dbg(X + a + b);
	// dbg((X + X + 1) * (X + X + 2) / 2);

	long long cnt = m - X - a - b;
	// dbg(ans, "asd");
	if(cnt >= 0) {
		// dbg(cnt);
		ans += sum(X + a + b, m, __gcd(a, b));
	}
	cout << ans << '\n';
}