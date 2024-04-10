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

const int N = 105;
int n, m;
char c = 'A', w[N][N];

int get_len(int x, int y) {
	int lg = 0;
	int yy = y;
	while(w[x][y] == w[x][yy]) yy--, lg++;
	return lg;
}

bool check(int x, int y, int lg) {
	for(int i = 0; i <= lg; i++)
		if(w[x + i][y] != 0)
			return false;
	for(int i = 0; i <= lg; i++)
		if(w[x + lg][y - i] != 0)
			return false;
	return true;
}
void put(int x, int y, int lg, char c) {
	for(int i = 0; i <= lg; i++)
		w[x + i][y] = c;
	for(int i = 0; i <= lg; i++)
		w[x + lg][y - i] = c;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 0; i <= m + 1; i++)
		w[n + 1][i] = 'X';
	for(int i = 0; i <= n + 1; i++)
		w[i][m + 1] = 'X';
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(w[i][j] != 0) continue;

			for(int c = 'A'; c <= 'F'; c++) {
				if(c == w[i - 1][j]) continue;
				if(c == w[i][j + 1]) continue;
				if(c == w[i][j - 1]) {
					int lg = get_len(i, j - 1);
					if(check(i, j, lg)) {
						put(i, j, lg, c);
						break;
					} else continue;
				} else {
					w[i][j] = c;
					break;
				}
			}
			// dbg(i, j, c);
	}

		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++)
				cout << w[i][j];
			cout << '\n';
	}
}