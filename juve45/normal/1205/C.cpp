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

// const int N = ;
int n, xx, yy, xx2, yy2, use[55][55], x;
char ans;

void que(int x, int y, int x2, int y2) {
	int sw = 0;
	if(x > x2 || y > y2) {
		sw = 1;
		swap(x, x2);
		swap(y, y2);
	}
	cout << "? " << x << ' ' << y << ' ' << x2 << ' ' << y2 << endl;
	cin >> ans;
	if(sw) {
		swap(x, x2);
		swap(y, y2);
	}
	if(ans == '0') {
		use[x2][y2] = 1 - use[x][y];
	}
	else use[x2][y2] = use[x][y];
}

int dx[] = {0, 2, 1, 0, -2, -1};
int dy[] = {2, 0, 1, -2, 0, -1};

void dfs(int x, int y, int lim = 6) {

	for(int i = 0; i < lim; i++)
		if(1 <= x + dx[i] && x + dx[i] <= n && 
			 1 <= y + dy[i] && y + dy[i] <= n && 
			 use[x + dx[i]][y + dy[i]] == -1) {
			que(x, y, x + dx[i], y + dy[i]);
			dfs(x + dx[i], y + dy[i], lim);
		}

}


int qq(int x, int y, int x2, int y2) {
	cout << "? " << x << ' ' << y << ' ' << x2 << ' ' << y2 << endl;
	cin >> ans;
	return ans;
}

pair<int, int> nxt(pair<int, int> p) {
	if(p.nd != n) return {p.st, p.nd + 1};
	return {p.st + 1, p.nd};
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;

	xx = n + 1;
	yy = n + 1;

	memset(use, -1, sizeof use);
	use[1][1] = 1;
	use[n][n] = 0;

	dfs(1, 1, 3);

	// dbg(xx, yy);
	if(xx == n + 1 && yy == n + 1)
		xx = n - 1, yy = n - 1;

	use[1][2] = use[2][2];
	dfs(1, 2);
	vector <pair<pair<int, int>, pair<int, int> > > v;

	pair<int, int> a = {1, 1}, b = {1, 2}, c = {1, 3};
	pair<int, int> d = nxt(c);
	for(int i = 1; i + 3 <= 2 * n - 1; i++) {
		if(use[a.st][a.nd] ^ use[b.st][b.nd] ^ use[c.st][c.nd] ^ use[d.st][d.nd] == 0) {
			x = qq(a.st, a.nd, d.st, d.nd) - '0';
			if(x == 1 && use[a.st][a.nd] == use[d.st][d.nd])
				x = 0;
			else if(x == 0 && use[a.st][a.nd] == use[d.st][d.nd])
				x = 1;
			break;
		}
		a = nxt(a);
		b = nxt(b);
		c = nxt(c);
		d = nxt(d);
	}


	cout << "!\n";
	for(int i= 1; i <= n; i++) {
		for(int j = 1; j <= n; j++)
			if((i + j) % 2 == 1)
				cout << (use[i][j] ^ x);
			else 
				cout << (use[i][j]);

		cout << '\n';
	}
	fflush(stdout);
}