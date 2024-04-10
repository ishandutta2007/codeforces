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

const int N = 500100;
int n, nxt[N], use[N], curr;

vector <int> v[N];

void dfs(int node) {
	if(nxt[node] != -1 && !use[nxt[node]])
		dfs(nxt[node]);
	use[node] = curr--;
}

bool check() {
	stack<int> s;
	s.push(n + 10);
	for(int i = 1; i <= n; i++) {
		// dbg(i);
		if(nxt[i] == -1) continue;
		while(!s.empty() && s.top() <= i)
			s.pop();
		// dbg_ok;
		if(nxt[i] > s.top()) return 0;
		s.push(nxt[i]);
	}
	return 1;
}

void solve() {
	for(int i = 1; i <= n + 11; i++) use[i] = 0;
	// e.clear();
	scanf("%d ", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d ", nxt + i);
		// if(nxt[i] != -1)
		// 	e.push_back({i, nxt[i]});
	}

	if(!check()) {
		printf("-1\n");
		return;
	}

	curr = n;
	use[n + 1] = 1;
	for(int i = 1; i <= n; i++)
		if(!use[i])
			dfs(i);
	for(int i = 1; i <= n; i++)
		printf("%d ", use[i]);
		// cout << use[i] << ' ';
	printf("\n");
}


int main() {
	int t; 
	scanf("%d ", &t);
	while(t--)
		solve();
}