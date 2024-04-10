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

const int N = 505;
int n, m, tot;
string s[N];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool ok(int x, int y) {
	if(s[x][y] == '.')
	 return 0;
	
	int nr = 1;

	for(int i = 0; i < 4; i++) {
		int xx = x, yy = y;
		int nrc = 0;
		while(s[xx][yy] == '*') {
			nrc++;
			xx += dx[i];
			yy += dy[i];
		}
		if(nrc == 1) return 0;
		nr += nrc - 1;
	}
	dbg(nr);
	dbg(tot);
	if(nr == tot)
		return 1;
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	s[0] = s[n + 1] = string(m + 2, '.');
	// dbg(s[0]);
	for(int i = 1; i <= n; i++)  {
		cin >> s[i];
		s[i] = "." + s[i] + '.';
		for(auto j : s[i])
			tot += (j == '*');
	}


	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(ok(i, j))
				return  cout << "YES\n", 0;
	cout << "NO\n";
}