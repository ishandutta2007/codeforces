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
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const long long N = 5005;
long long n, l[N], r[N], v[N], a[N], op[N], m, off[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(long long i = 1; i <= n; i++) a[i] = 1e9;

	for(long long i = 1; i <= m; i++) {
		cin >> op[i] >> l[i] >> r[i] >> v[i];
		if(op[i] == 1) {
			for(long long j = l[i]; j <= r[i]; j++)
				off[j] += v[i];
		} else {
			for(long long j = l[i]; j <= r[i]; j++)
				a[j] = min(a[j], v[i] - off[j]);
		}
	}

	memset(off, 0, sizeof off);

	for(long long i = 1; i <= m; i++) {
		if(op[i] == 1) {
			for(long long j = l[i]; j <= r[i]; j++)
				off[j] += v[i];
		} else {
			long long mx = -1e9;
			for(long long j = l[i]; j <= r[i]; j++)
				mx = max(mx, a[j] + off[j]);
			if(mx != v[i])
				return cout << "NO\n", 0;
		}
	}
	cout << "YES\n";
	for(long long i = 1; i <= n; i++) 
		cout << a[i] << ' ';
}