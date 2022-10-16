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

const int N = 110;
int n, m, q, r, c, x, op, w[N][N], val[N * N];

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> q;

	int k = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			w[i][j] = k++;

	for(int i = 1; i <= q; i++) {
		cin >> op;
		if(op == 1) {
			cin >> x;
			
			w[x][m + 1] = w[x][1];
			for(int i = 1; i <= m; i++)
				w[x][i] = w[x][i + 1];

		} else if(op == 2) {
			cin >> x;

			w[n + 1][x] = w[1][x];
			for(int i = 1; i <= n; i++)
				w[i][x] = w[i + 1][x];
		} else {
			cin >> r >> c >> x; 
			val[w[r][c]] = x;
		}

	}

	k = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cout << val[k++] << " \n"[j == m];

}