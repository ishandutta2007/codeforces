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

const int N = 300100;
int n, a, b, f[N], ok[N], m;
set <int> v[N];

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		f[a]++;
		f[b]++;
		v[a].insert(i);
		v[b].insert(i);
	}

	for(int i = 1; i <= n; i++) {
		if(f[i] >= m / 2) {
			memset(ok, 0, sizeof ok);
			
			for(auto j : v[i])
				ok[j] = 1;

			int sz1 = v[i].size();
			if(sz1 == m)
				return cout << "YES\n", 0;
			// dbg(i, sz1);
			for(int j = 1; j <= n; j++)
				if(i != j) {
					int sz2 = 0;
					for(auto k : v[j])
						if(!ok[k])
							sz2++;
					if(sz1 + sz2 == m) {
						// dbg(i, j, sz1, sz2);
						return cout << "YES\n", 0;
					}
				}

		}
	}
	cout << "NO\n";
}