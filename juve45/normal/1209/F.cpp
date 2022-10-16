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

const int N = 1001000;
const int MOD = 1e9 + 7;
int n, up[26][N], d[N], dp[N], m, a, b;

vector <int> v[N ];
map <pair<int, int>, int> edg;

pair<int, int> get_anc(int a, int b) {
	for(int i = 25; i >= 0; i--) {
		if(up[i][a] == -1 || up[i][b] == -1 || dp[up[i][a]] == dp[up[i][b]])
			continue;
		a = up[i][a];
		b = up[i][b];
	}
	return {a, b};
}

void upd_anc(int node, int fth) {
	up[0][node] = fth;
	for(int i = 1; i <= 25; i++) {
		if(up[i - 1][node] == -1) up[i][node] = -1;
		else up[i][node] = up[i - 1][up[i - 1][node]];
	}
}

void dijkstra(int start) {

	memset(up, -1, sizeof up);
	memset(d, 0x3f, sizeof d);

	priority_queue <pair<int, int>> pq;
	d[start] = 0;
	dp[0] = 0;

	pq.push({0, start});

	while(!pq.empty()) {
		auto p = pq.top(); pq.pop();
		int x = p.nd;
		if(-p.st > d[x]) continue;
		// dbg(x, dp[x], d[x]);

		for(auto i : v[x]) {
			// dbg(i, x, d[i], d[x]);
			if(d[i] == d[x] + 1) {
				auto anc = get_anc(x, up[0][i]);
				if(anc.st == x && dp[x] == dp[anc.nd]) {
					if(edg[{x, i}] < edg[{up[0][i], i}])
					dp[i] = (dp[x] * 10LL + edg[{x, i}]) % MOD,
					upd_anc(i, x);
				} else if(edg[{up[0][anc.st], anc.st}] < edg[{up[0][anc.nd], anc.nd}]) {
					dp[i] = (dp[x] * 10LL + edg[{x, i}]) % MOD;
					upd_anc(i, x);
				}
				// dbg(anc, dp[i]);
			} else if(d[i] > d[x] + 1) {
				d[i] = d[x] + 1;
				dp[i] = (dp[x] * 10LL + edg[{x, i}]) % MOD;
				pq.push({-d[i], i});
				upd_anc(i, x);
			}
			// dbg(i, dp[i]);
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	int last_node = n;
	for(int i = 1; i <= m; i++) {
		cin >> a >> b;
		string ss = to_string(i);
		int last = a;

		for(int j = 0; j + 1 < ss.size(); j++) {
			last_node++;
			v[last].push_back(last_node);
			v[last_node].push_back(last);
			edg[{last, last_node}] = ss[j] - '0';
			edg[{last_node, last}] = ss[ss.size() - j - 1] - '0';
			last = last_node;
		}
		
		v[last].push_back(b);
		v[b].push_back(last);
		edg[{last, b}] = ss.back() - '0';
		edg[{b, last}] = ss[0] - '0';
	}

	// dbg(edg);

	dijkstra(1);

	for(int i = 2; i <= n; i++) cout << dp[i] << '\n';
}