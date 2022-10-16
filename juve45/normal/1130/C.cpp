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
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }

const int N = 55;
const int MOD = 666013;
int n, k, xs, ys, xf, yf;
string m[N];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

bool ok(int x, int y) {
	if(x < 0 || y < 0) return false;
	if(x >= n || y >= n) return false;
	return m[x][y] == '0';
}

void fill(int x, int y, char val) {
	m[x][y] = val;
	for(int i = 0; i < 4; i++)
		if(ok(x + dx[i], y + dy[i]))
			fill(x + dx[i], y + dy[i], val);
}

int dist(int xa, int ya, int xb, int yb) {
	int X = xa - xb;
	int Y= ya - yb;
	return X*X + Y*Y;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	cin >> xs >> ys;
	cin >> xf >> yf;
	xs--;
	ys--;
	xf--;
	yf--;

	for(int i = 0 ;i < n; i++) cin >> m[i];

	fill(xs, ys, 'a');
	if(m[xf][yf] == 'a') 
		return cout << "0\n", 0;
	fill(xf, yf, 'b');

	int ans = 1e9;
	for(int i = 0; i < n * n; i++)
		for(int j = 0; j < n * n; j++)
			if(m[i / n][i % n] == 'a' && m[j / n][j % n] == 'b')
				ans = min(ans, dist(i / n, i % n, j / n, j % n));

	cout << ans << '\n';
}