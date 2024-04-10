#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

// using namespace __gnu_pbds; 
using namespace std;

#define st first
#define nd second

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}
// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"



const int N = 10003;
int n, k, m, a, b, x[N], y[N];
bool use[N][N], init[N][N], usec[N], usel[N];
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

vector <int> lin[N], col[N];

inline bool ok(int ind) {
	if(use[x[ind]][y[ind]]) return 0;
	return 1;
}

int bfs(int xx, int yy) {

	vector <pair<int, int> > q;
	q.push_back({xx, yy});
	use[xx][yy] = 1;

	int pas = 0, ans = 1e9;
	while(!q.empty()) {	
		vector <pair<int, int> > q2;

		// dbg(q);

		for(int a = 0; a < q.size(); a++) {
			auto pp = q[a];
			// dbg(pp);/);
			if(pp.st == n && pp.nd == m) ans = min(ans, pas);
			if(pp.st == n || pp.nd == m) ans = min(ans, pas + 1);
			if(pp.st >= n - 2 || pp.nd >= m - 2) 
				if(init[n][m]) ans = min(ans, pas + 1);
			// 	else if(pp.st >= n - 1 || pp.nd >= m - 1) ans = min(ans, pas + 2);

			for(int i = 0; i < 4; i++)
				if(!use[pp.st + dx[i]][pp.nd + dy[i]] && init[pp.st + dx[i]][pp.nd + dy[i]])
					use[pp.st + dx[i]][pp.nd + dy[i]] = 1,
					q.push_back({pp.st + dx[i], pp.nd + dy[i]});
		}
		// dbg(q);

		for(auto pp : q) {
			if(pp.st + 1 == n) ans = min(ans, pas + 1);
			if(pp.nd + 1 == m) ans = min(ans, pas + 1);
			for(int w = -2; w <= 2; w++) {
				if(pp.st + w > 0 && !usel[pp.st + w]) for(auto i : lin[pp.st + w]) if(ok(i)) use[x[i]][y[i]] = 1, q2.push_back({x[i], y[i]});
				if(pp.nd + w > 0 && !usec[pp.nd + w]) for(auto i : col[pp.nd + w]) if(ok(i)) use[x[i]][y[i]] = 1, q2.push_back({x[i], y[i]});
				if(pp.st + w > 0) usel[pp.st + w] = 1;
				if(pp.nd + w > 0) usec[pp.nd + w] = 1;
			}
			// if(!usel[pp.st - 1]) for(auto i : lin[pp.st - 1]) if(ok(i)) use[x[i]][y[i]] = 1, q2.push_back({x[i], y[i]});
			// if(!usel[pp.st + 1]) for(auto i : lin[pp.st + 1]) if(ok(i)) use[x[i]][y[i]] = 1, q2.push_back({x[i], y[i]});
			// if(!usec[pp.nd - 1]) for(auto i : col[pp.nd - 1]) if(ok(i)) use[x[i]][y[i]] = 1, q2.push_back({x[i], y[i]});
			// if(!usec[pp.nd + 1]) for(auto i : col[pp.nd + 1]) if(ok(i)) use[x[i]][y[i]] = 1, q2.push_back({x[i], y[i]});
			// usec[pp.nd] = usec[pp.nd - 1] = usec[pp.nd + 1] = 1;
			// usel[pp.st] = usel[pp.st - 1] = usel[pp.st + 1] = 1;
				// dbg(q2.size());
		}
		// dbg(q2);
		q = q2;
		pas++;
	}
	if(ans < 1e9)
		return ans;
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	for(int i = 1; i <= k; i++) {
		cin >> x[i] >> y[i];
		init[x[i]][y[i]] = 1;
		lin[x[i]].push_back(i);
		col[y[i]].push_back(i);
	}

	// if(!init[n][m]) {
	// 	init[n][m] = 1;
	// 	x[k + 1] = n;
	// 	y[k + 1] = m;
	// 	lin[n].push_back(k + 1);
	// 	col[m].push_back(k + 1);
	// }


	cout << bfs(1, 1) << '\n';

}