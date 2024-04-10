#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << '\n'; return out;}
// template<class T> ostream& prnt(ostream& out, T v) { out << '['; for(auto e : v) out << e << ' '; return out << ']';}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, deque <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 333;
int n, m, tot;
string ss;
deque<int> s[N][N], t[N][N];
vector <pair<pair<int, int>, pair<int, int> > > ans;

void move(int x, int y, int a, int b) {
	assert(x == a || y == b);
	// cout << x + 1 << ' ' << y + 1 << ' ' << a + 1 << ' ' << b + 1 << '\n';
	// dbg(x, y, a, b);
	assert(x != a || y != b);
	// dbg(s[x][y]);
	ans.push_back({{x + 1, y + 1}, {a + 1, b + 1}});
	s[a][b].push_front(s[x][y].back());
	s[x][y].pop_back();
	// dbg_ok;
}

void move_last(int x, int y) {
	for(auto k : t[x][y])
		if(k == 0)
			move(n - 1, 0, n - 1, m - 1);
		else 
			move(0, m - 1, n - 1, m - 1);
}

void move_back(int x, int y) {
	for(int i = 0; i < t[x][y].size(); i++)
		move(n - 1, m - 1, x, y);
}
void move_out(int i, int j) {
	while(!s[i][j].empty()) move(i, j, n - 1, m - 1);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) {
			cin >> ss;
			for(auto k : ss)
				s[i][j].push_back(k - '0');
		}

	for(int i = 0; i < n; i++) 
		for(int j = 0; j < m; j++) {
			cin >> ss;
			tot += ss.size();
			for(auto k : ss)
				t[i][j].push_back(k - '0');
		}

	// dbg_ok;

	move_out(0, m - 1);
	move_out(n - 1, 0);

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			// dbg(i, j);

			if(i == 0 && j == m - 1 || i == n - 1 && j == 0)
				continue;
			else {
				while(!s[i][j].empty()) {
					int k = s[i][j].back();
					if(k == 0) {
						if(j != 0) move(i, j, i, 0);
						if(i != n - 1) move(i, 0, n - 1, 0);
					} else {
						if(i != 0) move(i, j, 0, j);
						if(j != m - 1) move(0, j, 0, m - 1);
					}
				}
			}
		}
	// dbg_ok;
	// dbg(s[n - 1][0]);
	// dbg(s[0][m - 1]);

	// // return 0;

	// dbg(ans);
	// dbg(ans.size(), tot);
	assert(ans.size() <= 2 * tot);
	// // for(int i = 0; i < n; i++)
	// 	for(int j = 0; j < m; j++) {
 // 			dbg(i, j, s[i][j]);
	// 		assert(s[i][j] == t[i][j]);
	// 	}
	
	for(int i = n - 1; i >= 0; i--)
		for(int j = m - 1; j >= 0; j--) {
			// dbg(i, j);

			reverse(t[i][j].begin(), t[i][j].end());
			if(i == 0 && j == m - 1 || i == n - 1 && j == 0 || i == n - 1 && j == m - 1)
				continue;
			else {
				for(auto k : t[i][j]) {
					if(k == 0) {
						if(i != n - 1) move(n - 1, 0, i, 0);
						if(j != 0) move(i, 0, i, j);
					} else {
						if(j != m - 1) move(0, m - 1, 0, j);
						if(i != 0) move(0, j, i, j);
					}
				}
				// dbg(i, j, s[i][j]);
			}
		}
	

	move_last(n - 1, 0);
	move_last(0, m - 1);
	move_last(n - 1, m - 1);

	move_back(n - 1, 0);
	move_back(0, m - 1);
	
	int max_sz = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++) {
			max_sz += t[i][j].size();
			reverse(t[i][j].begin(), t[i][j].end());
 			// dbg(i, j, s[i][j]);
			assert(s[i][j] == t[i][j]);
		}
	// if(ans.size() > 4 * tot) while(1);
	// dbg(max_sz);
	cout << ans << '\n';
}