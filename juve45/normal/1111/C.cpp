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
long long n, k, a, b, v[N];

long long destroy(long long mn, long long mx, long long l, long long r) {
	if(l > r) return a;
	if(mx == mn) return b * (r - l + 1);
	long long mid = (mn + mx) / 2;

	long long mrg = l;
	while(mrg <= r && v[mrg] <= mid) mrg++;

	long long ret = min(destroy(mn, mid, l, mrg - 1) + destroy(mid + 1, mx, mrg , r), b * (r - l + 1) * (mx - mn + 1));
	// dbg(mn, mx, l, r, ret);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> k >> a >> b;
	for(long long i = 1; i <= k; i++)
		cin >> v[i];
	sort(v + 1, v + k + 1);

	cout << destroy (1, (1 << n), 1, k) << '\n';
}