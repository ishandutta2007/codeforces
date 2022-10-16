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

const int N = 101;
int n;


string w[N];
int dx[]  = {1, 1, -1, -1, 2, 2, -2, -2};
int dy[]  = {2, -2, 2, -2, 1, -1, 1, -1};

bool ok(int x, int y) {
	if(x < 0 || y < 0) return 0;
	if(x >= n || y >= n) return 0;
	if(w[x][y] != '.') return 0;
	return 1;
}

void dfs(int x, int y, int c = 1) {
	w[x][y] = (c ? 'B' : 'W');

	for(int i = 0; i < 8; i++)
		if(ok(x + dx[i], y + dy[i]))
			dfs(x+ dx[i], y + dy[i], 1- c);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i  =0; i < n; i++) w[i] = string(n, '.');

	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(w[i][j] == '.')
				dfs(i, j);
	for(int i =0 ; i < n; i++) cout << w[i] << '\n';
}