#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp> //required
// #include <ext/pb_ds/tree_policy.hpp> //required

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

#define st first
#define nd second

// using namespace __gnu_pbds; 
using namespace std;

// template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // ordered_set <int> s;
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 1010;
int n, k, m, a[N][N], xmin = 1e9, xmax, ymin = 1e9, ymax, use[N * N];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

vector <int> v[N * N];

bool filled(int xa, int ya, int xb, int yb) {
	if(xa > xb) swap(xa, xb);
	if(ya > yb) swap(ya, yb);

	if(xa < 1 || ya < 1) return 0;
	if(xb > n || yb > m) return 0;
	
	for(int i = xa; i <= xb; i++)
		for(int j = ya; j <= yb; j++)
			if(a[i][j] == 0)
				return 0;
	return 1;
}

void fill(int xa, int ya, int xb, int yb, int k) {
	if(xa > xb) swap(xa, xb);
	if(ya > yb) swap(ya, yb);
	for(int i = xa; i <= xb; i++)
		for(int j = ya; j <= yb; j++)
			a[i][j] = k;
}

int bfs(int start) {
	int cnt = 0;
	memset(use, 0, sizeof use);
	queue <int> q;
	q.push(start);
	use[start] = 1;
	while(!q.empty()) {
		auto x = q.front();
		cnt++;
		q.pop();
		for(auto i : v[x])
			if(!use[i])
				q.push(i), use[i] = 1;
	}
	return cnt;

}

bool test(int k) {
	
	// dbg(k);

	int nr = 0, x, y, impar = 0;

	for(int i = xmin; i <= xmax; i += k)
		for(int j = ymin; j <= ymax; j += k) {
			if(a[i][j] == 0) continue;
			v[i * N + j].clear();
			
			x = i; y = j;
			nr++;
			for(int dir = 0; dir < 4; dir++) 
				if(filled(i, j, i + k * dx[dir], j + k * dy[dir])) {
					v[i * N + j].push_back((i + k * dx[dir]) * N + j + k * dy[dir]);
					fill(i, j, i + k * dx[dir], j + k * dy[dir], k);
				}
			
			if(v[i * N + j].size() % 2 == 1) impar++;
			// dbg(v[i * N + j]);
		}

	if(impar != 0 && impar != 2)
		return 0;

	//check all positions are k
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j] && a[i][j] != k)
				return 0;

	//check this graph is connex
	if(bfs(x * N + y) != nr)
		return 0;


	return 1;
}



int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if(a[i][j]) {
				xmin = min(i, xmin);
				xmax = max(i, xmax);
				ymin = min(j, ymin);
				ymax = max(j, ymax);
			}
		}

	int g = __gcd(xmax - xmin, ymax - ymin);
	// dbg(g);
	// exista un singur a[i];
	if(g == 0) 
		return cout << "-1\n", 0;

	vector <int> ans;
	for(int i = 2; i <= g; i++)
		if(g % i == 0)
			if(test(i))
				ans.push_back(i);

	if(ans.size() == 0) ans.push_back(-1);
	cout << ans << '\n';
}