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

const int N = 100100;
int n, v[31][N], l[N], r[N], q[N], m, a[N];

void process(int l, int r, int q) {
	for(int i = 0; i < 30; i++)
		if((1 << i) & q) {
			v[i][l]++, v[i][r + 1]--;
		}
}
bool check(int l, int r, int q) {
	for(int i = 0; i < 30; i++)
		if(! ((1 << i) & q))
			if(v[i][r] - v[i][l - 1] == (r - l + 1)) 
				return 0;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> l[i] >> r[i] >> q[i];
		process(l[i], r[i], q[i]);
	}
	dbg_ok;
	for(int i = 0; i < 30; i++)
		for(int j = 1; j <= n; j++)
			v[i][j] += v[i][j - 1];

	for(int i = 0; i < 30; i++)
		for(int j = 1; j <= n; j++)
			v[i][j] = min(v[i][j], 1);

	for(int i = 1; i <= n; i++)
		for(int j = 0; j < 30; j++)
			if(v[j][i])
				a[i] += (1 << j);
	
	for(int i = 0; i < 30; i++)
		for(int j = 1; j <= n; j++)
			v[i][j] += v[i][j - 1];

	for(int i = 1; i <= m; i++)
		if(!check(l[i], r[i], q[i])) 
			return cout << "NO\n", 0;

	cout << "YES\n";
	for(int i =1; i <= n; i++ )
		cout << a[i] << ' ';
	cout << '\n';
	return 0;
}