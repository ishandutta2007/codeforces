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

const long long N = 3005;
long long n, m, a, b, g, z, x, y, w[N][N], mn[N][N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> a >> b;
	cin >> g >> x >> y >> z;

	for(long long i = 1; i <= n; i++)
		for(long long j = 1; j <= m; j++) {
			w[i][j] = g;
			g = (1LL * g * x + y) % z;
		}

	for(long long i = 1; i <= n; i++) {
		deque <long long> dq;
		for(long long j = 1; j <= b; j++) {
			while(!dq.empty() && w[i][dq.back()] > w[i][j])
				dq.pop_back();
			dq.push_back(j);
		}
		
		mn[i][1] = w[i][dq.front()];

		for(long long j = 2; j <= m - b + 1; j++) {
			// dbg(j + b - 1);
			
			if(!dq.empty() && dq.front() < j) dq.pop_front();

			while(!dq.empty() && w[i][dq.back()] > w[i][j + b - 1])
				dq.pop_back();
			dq.push_back(j + b - 1);
			// dbg(dq.front());
			mn[i][j] = w[i][dq.front()];
		}
	}

	long long ans = 0;
	for(long long j = 1; j <= m - b + 1; j++) {
		deque <long long> dq;
		for(long long i = 1; i <= a; i++) {
			while(!dq.empty() && mn[dq.back()][j] > mn[i][j])
				dq.pop_back();
			dq.push_back(i);
		}
		
		// dbg(1, j, mn[dq.front()][j]);
		ans += mn[dq.front()][j];


		for(long long i = 2; i <= n - a + 1; i++) {
			// dbg(j + b - 1);
			
			if(!dq.empty() && dq.front() < i) dq.pop_front();

			while(!dq.empty() && mn[dq.back()][j] > mn[i + a - 1][j])
				dq.pop_back();
			dq.push_back(i + a - 1);
			// dbg(dq.front());
			// dbg(i, j, mn[dq.front()][j]);
			ans += mn[dq.front()][j];
		}
	}

	// dbg_v(w[1], m + 1);
	// dbg_v(w[2], m + 1);
	// dbg_v(w[3], m + 1);


	// dbg_v(mn[1], m + 1);
	// dbg_v(mn[2], m + 1);
	// dbg_v(mn[3], m + 1);
	cout << ans << '\n';
}