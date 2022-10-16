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

const int N = 200100;
int n, a, b, last[N], ans, mark[N];
vector <int> v[N];

void dfs(int node, int ant = -1, int lvl = 0) {

	last[node] = -1;

	bool ok = 0;

	for(auto i : v[node])
		if(i != ant) {
			dfs(i, node, lvl + 1);
			if(mark[i])
				ok = 1;
		}

	if(mark[node]) ok = 1;
	
	if(lvl > 2 && !ok && !mark[ant]) {
		mark[ant] = 1;
		ans++;
	}
	// dbg(last[node]);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);
	cout << ans << '\n';
}