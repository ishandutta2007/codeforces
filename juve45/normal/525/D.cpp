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

const int N = 2019;
int n, m;
int val[256];
string s[N];

int main() {

	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	
	val['*'] = 1;
	val['.'] = 0;

	s[0] = string(m + 2, '*');
	s[n + 1] = string(m + 2, '*');
	for(int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = "*" + s[i] + "*";
	}
	queue <pair<int, int> > q;

	for(int i = 1; i <= n; i++)
		for(int j = 1;  j<= m; j++)
			if(s[i][j] == '.')
				q.push({i, j});
	
	while(!q.empty()) {
		auto p = q.front();
		q.pop();
		
		// dbg(p);

		for(int i = p.st -1; i <= p.st; i++)
			for(int j = p.nd-1; j <= p.nd; j++) {
				int nr = 0;
				for(int ii = 0; ii <= 1; ii++)
					for(int jj = 0; jj <= 1; jj++)
						nr += val[s[i + ii][j + jj]];

				// dbg(i, j, nr);
				
				if(nr == 1)
					for(int ii = 0; ii <= 1; ii++)
						for(int jj = 0; jj <= 1; jj++)
							if(s[i + ii][j + jj] == '*') {
								s[i + ii][j + jj] = '.';
								q.push({i + ii, j + jj});
							}
			}

	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			cout << s[i][j] ;
		cout << '\n';
	}

}