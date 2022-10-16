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
int n, start, k, dp[N], c[N], x, a, b;
vector <int> v[N], cc[N];


void dfs(int node, int ant = -1) {
	int mx = 0;
	dp[node] = c[node];
	for(auto i : v[node])
		if(i != ant) {
			dfs(i, node);
			dp[node] += dp[i];
			mx = max(mx, dp[i]);
		}
	mx = max(mx, 2 * k - dp[node]);
	if(mx <= k) start = node;
}

void dfs2(int node, int ant, int place) {
	// dbg(node);
	if(c[node]) cc[place].push_back(node);

	for(auto i : v[node])
		if(i != ant) 
			dfs2(i, node, place);
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;

	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);	
	}

	for(int i = 1; i <= 2 * k; i++)
		cin >> x, c[x] = 1;

	dfs(1);

	int nrc = 0;
	for(auto i : v[start])
		dfs2(i, start, nrc++);

	priority_queue <pair<int, int>  > pq; 
	for(int i = 0; i < nrc; i++) 
		pq.push({cc[i].size(), i});

	if(c[start]) {
		cc[nrc].push_back(start);
		pq.push({1, nrc});
	}

	cout << "1\n" << start << endl;


	for(int i = 1; i <= k; i++) {
		// dbg(pq.top());
		assert(!pq.empty());
		int x = pq.top().nd; pq.pop();
		int y = pq.top().nd; pq.pop();

		cout << cc[x].back() << ' ' << cc[y].back() << ' ' << start << '\n';
		cc[x].pop_back();
		cc[y].pop_back();

		if(!cc[x].empty()) pq.push({cc[x].size(), x});
		if(!cc[y].empty()) pq.push({cc[y].size(), y});
	}

	return 0;
}