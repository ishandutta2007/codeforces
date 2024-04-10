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

const int N = 300100;
int n, a[N][8], b[N], f[66000], m;

bool ok(int val, int print = 0) {

	memset(f, 0, sizeof f);
	for(int i = 1; i <= n; i++) {
		b[i] = 0;
		for(int j = 0; j < m; j++)
			if(a[i][j] >= val)
				b[i] ^= (1 << j);

		f[b[i]] = i;
	}

	for(int i = 0; i < (1 << m); i++)
		for(int j = i; j < (1 << m); j++) {
			if((i | j) == (1 << m) - 1 && f[i] && f[j]) {
				if(print) cout << f[i] << ' ' << f[j] << '\n';
				return 1;
			}
		}
	return 0;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= n; i++) 
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	

	int l = 0, r = 1e9;
	while(l != r) {
		int mid = (l + r + 1) / 2;
		if(ok(mid)) l = mid;
		else r = mid - 1;
	}

	ok(l, 1);

}