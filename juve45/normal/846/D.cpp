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

const int N = 505;
const int B = 1e9;
int n, m, k, q, x, y, t;
vector <pair<int, pair<int, int> > > v;

bool ok(int val) {
	int mat[N][N];
	memset(mat,0, sizeof mat);

	for(auto i : v)
		if(i.st <= val)
			mat[i.nd.st][i.nd.nd] = 1;

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];

	for(int i = 1; i + k - 1 <= n; i++)
		for(int j = 1; j + k - 1 <= m; j++)
			if( mat[i + k - 1][j + k - 1] - mat[i - 1][j + k - 1] - mat[i + k - 1][j - 1] + mat[i - 1][j - 1] == k * k)
				return 1;
	return 0;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> k >> q;
	for(int i = 1; i <= q; i++) {
		cin >> x >> y >> t;
		v.push_back({t, {x, y}});
	}

	
	int l = 0, r = B + 1000;
	while(l != r) {
		int mid = (l + r) / 2;
		if(ok(mid)) r = mid;
		else l = mid + 1;
	}
	
	if(l > B) l = -1;

	cout << l << '\n';
}