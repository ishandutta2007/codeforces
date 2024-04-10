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

const int N = 2005;

int n, m, t, l, r, leq[N], geq[N], a[N], b[N], f[N];
vector <pair<int, int> > v;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> m;

	for(int i = 1; i <= n; i++) a[i] = 10 * n + 1 - i;

	for(int i = 1; i <= m; i++) {
		cin >> t >> l >> r;
		if(t == 1)  {
			f[l]++;
			f[r]--;
		}
		else
			v.push_back({l, r});
	}

	for(int i = 1; i <= n; i++)
		f[i] += f[i - 1];
	
	for(int i = 1; i <= n; i++)
		if(f[i] && f[i - 1] == 0)
			a[i] = 1;
		else if(f[i])
			a[i] = a[i - 1] + 1;

	for(int i = 1; i <= n; i++)
		if(f[i] == 0 && f[i - 1])
			a[i] = n * 11;

	for(auto i : v) {
		if(is_sorted(a + i.st, a + i.nd + 1)) 
		return cout << "NO\n", 0;
		// continue;
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++)
		cout << a[i] << ' ';
}