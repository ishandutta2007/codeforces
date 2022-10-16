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

const long long N = 200100;

long long n, use[N], a, b, t, x ,y, m;

vector <long long> v[N];

void dfs(long long node, long long col){
	use[node] |= col;
	// dbg(node);

	for(auto i : v[node]) 
		if((use[i] & col) == 0)
			dfs(i, col);
}


long long solve() {
	for(long long i = 1; i <= n; i++) use[i] = 0;

	use[a] = use[b] = 3;
	dfs(a, 1);
	// dbg_v(use, n + 1);
	dfs(b, 2);
	// dbg_v(use, n + 1);


	long long nr[3] = {0, 0, 0};

	for(long long i = 1; i <= n; i++)
		if(use[i] < 3)
			nr[use[i]]++;

	for(long long i = 1; i <= n; i++) use[i] = 0;

	dfs(a, 1);

	if(use[b] == 0)
		return 0;
	return nr[2] * nr[1];
}

int main() {
	
	ios_base::sync_with_stdio(false);
	

	cin >> t;
	// dbg(t);
	while(t--) {
		cin >> n >> m >> a >> b;
		for(long long i = 1; i <= n; i++) v[i].clear();
		for(long long i =1 ;i <=m; i++) {
			cin >>  x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cout << solve() << '\n';
	}

}