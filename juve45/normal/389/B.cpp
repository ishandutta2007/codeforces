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

const int N = 1020;
int n;
string s[N];
int dx[] = {1, 1, 1, 2};
int dy[] = {-1, 0, 1, 0};

bool ok(int x, int y) {
	// dbg(x, y);
	if(s[x][y] == '.') return 1;
	for(int i = 0; i < 4; i++)
		if(s[x + dx[i]][y + dy[i]] == '.')
			return 0;
		else s[x + dx[i]][y + dy[i]] = '.';
	return 1;
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;

	s[0] = string(n + 3, '.');
	s[n + 1] = string(n + 3, '.');
	s[n + 2] = string(n + 3, '.');
	for(int i = 1; i <= n;i++) {
		cin >> s[i];
		s[i] = "." + s[i] + ".";
	}

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(!ok(i, j))
				return cout << "NO\n", 0;

	cout << "YES\n";
}