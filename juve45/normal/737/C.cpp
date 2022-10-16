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
long long n, g[N], s, ans;

bool ok(long long nr) {

	long long req = 0;
	for(long long i = 2; i <= n - nr; i++)
		req += max(0LL, g[i] - g[i - 1] - 1);
	return (req <= nr);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> s;
	for(long long i =1; i <= n; i++) {
		cin >> g[i];
		if(g[i] == 0 && i != s) g[i] = 1e9;
	}
	if(g[s] != 0) ans++;
	g[s] = 0;

	sort(g + 1, g + n + 1);
	// dbg_v(g, n + 1);
	// dbg(ok(0));
	// return 0;

	long long l = 0, r = n;
	while(l != r) {
		long long mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	cout << l + ans << '\n';

}