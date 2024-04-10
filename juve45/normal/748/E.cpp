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

const int N = 1001000;
int n, a[N], lg[10 * N];
long long k;

bool ok(int lim) {
	long long nr = 0;
	for(int i = 1; i <= n; i++) {
		int mx = 0;

		int divide = a[i] / lim;
		divide = lg[divide];
		// dbg(a[i], lim, divide);

		for(int j = max(divide - 1, 0); j <= divide + 1; j++) {
			int p2 = (1 << j);
			int cat = a[i] / p2;
			int r = a[i] % p2;
			if(cat >= lim) mx = max(mx, p2);
			else if(cat + 1 >= lim) mx = max(mx, r);
		}
		// dbg(mx);
		nr += mx;
	}
	// dbg(nr);
	return nr >= k;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin>> a[i];

	lg[1] = 0;
	for(int i = 2; i < N * 10; i++)
		lg[i] = lg[i / 2] + 1;

	int l = 0, r = 10000000;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(ok(mid)) l = mid;
		else r = mid - 1;
	}
	if(l == 0) l = -1;
	
	cout << l << '\n';
}