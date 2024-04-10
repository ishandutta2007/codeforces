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

const int N = 1000100;
int n, f[N], x, y, t, f2[N], mx, m;

bool check(int n, int m, int x, int y) {
	if(x < 0 || y < 0 || x > n || y > m) return 0;

	memset(f2, 0, sizeof f2);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f2[abs(i - x) + abs(j - y)]++;
	for(int i = 0; i < t; i++)
		if(f[i] != f2[i])
			return 0;
	return 1;
}


int main() {
	ios_base::sync_with_stdio(false);

	cin >> t;
	for(int i = 1; i <= t; i++) {
		cin >> x; f[x]++;
		mx = max(x, mx);
	}

	if(f[0] != 1) return cout << "-1\n", 0;

	for(int i = 1; i <= t; i++)
		if(f[i] != 4 * i) {
			x = i;
			break;
		}

	for(int n = 1; n * n <= t; n++) {
		if(t % n == 0) {
			int m = t / n;
			int y1 = mx - (n - x) + 1;
			int y2 = mx - (m - x) + 1;
			// dbg(n, m ,x, y);
			// dbg(n, m, x, y);

			if(check(n, m, n - x + 1, y1)) {
				cout << n << ' ' << m <<  '\n';
				cout << n - x + 1 << ' ' << y1 <<  '\n';
				return 0;
			} else if(check(n, m, y2, m - x + 1)) {
				cout << n << ' ' << m <<  '\n';
				cout << y2 << ' ' << m - x + 1 <<  '\n';
				return 0;
			}

		}
	}

	cout << "-1\n";
}