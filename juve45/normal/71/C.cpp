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
int n, bad[N], f[N], a[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];

	for(int i = 3; i <= n; i++) {
		if(bad[i]) continue;
		for(int j = 2 * i; j <= n; j += i)
			bad[j] = 1;
		if(n % i == 0) {
			int k = n / i;
			// dbg(k);
			memset(f, 0, sizeof f);
			for(int j = 0; j < n; j++)
				if(a[j])
					f[j % k]++;
			// dbg_v(f, 4);
			for(int j = 0; j < k; j++)
				if(f[j] == i) 
					return cout << "YES\n", 0;
		}

	}
	cout << "NO\n";
}